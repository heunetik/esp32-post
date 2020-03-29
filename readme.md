# ESP32: HTTP POST Request

## Getting started
To set up the sketch, you'll need to fill in the `ssid` and `password` variables with your network's data, and set the URL you want to send the request to on line `27`.

NOTE: HTTPClient reuse is enabled ( `http.setReuse(true);` )