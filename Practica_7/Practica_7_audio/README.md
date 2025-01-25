## **PRÀCTICA - 7 audio**
Alumne: **Bernat Rubiol**

>***PROGMEM:***
modificador d'emmagatzematge en C i C++ que s'utilitza en microcontroladors per indicar que les dades han de ser emmagatzemades a la memòria de programa (flash) en lloc de a la memòria RAM. La memòria de programa (PROGMEM) és una secció de la memòria del microcontrolador reservada per emmagatzemar dades que no necessiten ser modificades durant l'execució del programa, com ara dades constants, taules, configuracions i, en aquest cas, fitxers d'àudio.


## Exercici Pràctic 1 reproducció des de memòria interna

1. Descebre la sortida pel port sèrie

La sortida pel port sèrie és

 AAC done

cada cop que el fitxer AAC s'hagi acabat de reproduir. Això ens proporciona una indicació a temps real de quan ha finalitzat la reproducció del fitxer AAC.


2. Explicar el funcionament

El codi `.cpp` està dissenyat per reproduir un fitxer d'àudio AAC emmagatzemat a memòria de programa (PROGMEM) utilitzant un generador d'àudio AAC i una sortida d'àudio I2S.

El fitxer AAC era la veu de Homer Simpson.

1. Inclusió de biblioteques

- `Arduino.h`
- `AudioGeneratorAAC.h`: biblioteca per generar àudio a partir d'arxius AAC.
- `AudioOutputI2S.h`: biblioteca per a la sortida d'àudio utilitzant el protocol I2S.
- `AudioFileSourcePROGMEM.h`: proporciona una manera de llegir fitxers d'àudio emmagatzemats a la memòria de programa (PROGMEM).
- `sampleaac.h`: fitxer d'àudio AAC que es reproduirà. Està emmagatzemat a la memòria de programa (PROGMEM).



2. Declaració de variables globals:

 AudioFileSourcePROGMEM *in;

`in`: punter amb l'objecte `AudioFileSourcePROGMEM`, que s'utilitza per accedir al fitxer d'àudio emmagatzemat a PROGMEM.

 AudioGeneratorAAC *aac;

`aac`: punter a fi `AudioGeneratorAAC`, que s'encarrega de descodificar i generar àudio a partir de l'arxiu AAC.

 AudioOutputI2S *out;

`out`: punter amb l'objecte `AudioOutputI2S`, que s'utilitza per a la sortida d'àudio mitjançant el protocol I2S.

3. Funció `setup()`:

```cpp
void setup() {
  Serial.begin(115200);
  audioLogger = &Serial;
  in = new AudioFileSourcePROGMEM(sampleaac, sizeof(sampleaac));
  aac = new AudioGeneratorAAC();
  out = new AudioOutputI2S();
  aac->begin(in, out);
}
```

S'inicia la comunicació serial a una velocitat de 115.200 bauds per a la sortida de missatges de depuració.

S'estableix `audioLogger` per dirigir la sortida de missatges d'àudio al port sèrie.

Es crea l'objecte `AudioFileSourcePROGMEM` anomenat `in`, `AudioGeneratorAAC` anomenat `aac` i `AudioOutputI2S` anomenat `out`.

S'anomena el mètode `begin()` de `aac`, passant com a arguments l'objecte `in` i `out`, per iniciar la reproducció de l'àudio AAC.

4. Funció `loop()`:

```cpp
void loop() {
  if (aac->isRunning()) {
    aac->loop();
  } else {
    Serial.printf("AAC doni\n");
    delay(1000);
  }
}
```

Es comprovarà si el generador d'àudio AAC està en funcionament.
- Si està en funcionament, s'anomena el mètode `loop()` d'aac per processar l'àudio.
- Si la reproducció s'ha acabat, s'imprimeix "AAC done" pel port sèrie i s'espera un segon abans de repetir el cicle.

5. Muntatge

![Muntatge](exercici1.png)
