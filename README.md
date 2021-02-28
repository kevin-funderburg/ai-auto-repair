# AI Auto Repair

<!-- summary -->

## About

<!-- more detail -->

## Configuration

<!-- how to set up -->

Build the program with:

    docker build . -t qt

### macOS
In order to run on macOS, X11 forwarding needs to be enabled. To achieve this, we will install 
- `socat` - a unix tool that creates two bidirectional streams between two endpoints.
- `xquartz`

Run the following commands to install these:

    brew install socat
    brew cask install xquartz

Once installed, open Xquartz.

    open -a Xquartz

Launch a shell and execute the following command and leave it running.

    socat TCP-LISTEN:6000,reuseaddr,fork UNIX-CLIENT:\"$DISPLAY\"

We are now ready to run the program, but first you must get your IP address of your system. Run the following command:

    ifconfig en0

This will produce output similar to this:

```
en0: flags=8863<UP,BROADCAST,SMART,RUNNING,SIMPLEX,MULTICAST> mtu 1500
	options=400<CHANNEL_IO>
	ether ff:ff:ff:ff:ff:ff
	inet6 ffff::fff:ffff:ffff:ffff%en0 prefixlen 64 secured scopeid 0x6
	inet 10.0.1.12 netmask 0xffffff00 broadcast 10.0.1.255
	nd6 options=201<PERFORMNUD,DAD>
	media: autoselect
	status: active
```
Where the IP Address we need is the numbers between `inet` and `netmask`, so in this case it's `10.0.1.12`.

Now that we have the IP Address, we can run the program using the following command (replacing `IP_ADDRESS` with the number gathered):

    docker run -e DISPLAY=IP_ADDRESS:0 qt:latest
## Licensing & thanks

This project is released under the [MIT License](./LICENSE.txt).

## Changelog

- v1.0.0
