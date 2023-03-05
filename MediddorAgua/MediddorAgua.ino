#define DEVICE_ID "0001"
#define BAUD_RATE 9600
#define RANDOM_SEED_PIN 5

int getTemperatura();
int getPresion();
int getCaudal();
void sendIntValue(char * name, int value);

void setup()
{
	Serial.begin(BAUD_RATE);
	randomSeed(analogRead(RANDOM_SEED_PIN));
}

void loop()
{
	if(Serial.available() > 0)
	{
		char lectura = Serial.read();

		switch(lectura)
		{
			case 't':
			case 'T':
			{
				sendIntValue("temperatura_celsius", getTemperatura());

				break;
			}

			case 'p':
			case 'P':
			{
				sendIntValue("presion_kPa", getPresion());

				break;
			}

			case 'c':
			case 'C':
			{
				sendIntValue("caudal_m3_seg", getCaudal());

				break;
			}

			default: break;
		}
	}
}

void sendIntValue(char * name, int value)
{
	Serial.println("{");
	Serial.print("\t\"device_id\": \"");
	Serial.print(DEVICE_ID);
	Serial.println("\"");
	Serial.print("\t\"name\": \"");
	Serial.print(name);
	Serial.println("\"");
	Serial.print("\t\"value\": ");
	Serial.println(value, DEC);
	Serial.println("}");
}

int getTemperatura()
{
	return random(10, 40);
}

int getPresion()
{
	return random(100, 150);
}

int getCaudal()
{
	return random(0, 600);
}