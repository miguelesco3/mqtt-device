# mqtt-device

## OBJETIVO

Este es un programa para enviar y recibir datos a través de mqtt. El concepto general parte de una clase dispositivo, de la que se derivan una clase sensor y una clase actuador. En este programa se utiliza la clase sensor para generar una clase particular para un sensor de temperatura y humedad dht22. Los valores captados por este sensor son adaptados y enviados por el protocolo mqtt.
