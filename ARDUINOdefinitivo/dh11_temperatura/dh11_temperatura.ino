// libreria sensore DHT-11
#include <dht11.h>
//libreria per display
#include <LiquidCrystal.h>
dht11 DHT;
#define DHT11_PIN 4
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // connessione display (pin)


void setup(){
  lcd.begin(16, 2); //display ha righe 16 colonne 2
  Serial.begin(9600); 
}

void loop()
{
  int chk;
  chk = DHT.read(DHT11_PIN);    // READ DATA

 // INVIO DATI TRAMITE SERIALE
 
  Serial.print(DHT.humidity,1); //stampa umidità su seriale
  Serial.print("-\t"); //spazio fra i due dati
  Serial.println(DHT.temperature,1); // stampa temperatura su seriale\
  delay(1000); //aspetta un secondo
  // VISUALIZZAZIONE SUL DISPLAY
    
	if (dht11.read(DHT11_PIN, &temperatura, &umidita, NULL)) {			
		Serial.print("Read DHT11 failed.");
		return;   
	}
	else
	{
		int t = dht.readTemperature();
		int h = dht.readHumidity();
		// posiziono il cursore alla colonna e riga 
		lcd.setCursor(0, 0); //stampo temperatura all'inizio
		lcd.print(t);
		lcd.setCursor(0, 1); //stampo umidità alla fine
		lcd.print(h);
	 
	}
}
