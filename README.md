#Firmware Adquisidor SmartWater
Firmware para hardware de adquisición de datos de un medidor de agua.
El código está hecho para funcionar en un Arduino UNO.

Los datos son valores simulados, los cuales pueden ser reemplazados por valores obtenidos por sensores para un trabajo futuro.

Se pueden solicitar los siguientes valores al arduino enviando el caracter correspondiente (se puede enviar mayúsculas):
- c --> caudal_m3_seg
- t --> temperatura_celsius
- p --> presion_kPa

El arudino responde con una cadena JSON con los siguientes campos:
- device_id: id del dispositivo.
- name: nombre de la variable.
- value: valor de la variable.

A continuación se puede visualizar un ejemplo de valores obtenidos.

{
 "device_id": "0001"
 "name": "temperatura_celsius"
 "value": 11
}

{
 "device_id": "0001"
 "name": "caudal_m3_seg"
 "value": 528
}

{
 "device_id": "0001"
 "name": "presion_kPa"
 "value": 148
}
