# Modul pro měření atmosférického tlaku a teploty a vlhkosti s BMP280 a SHT40

Outdoorový meteorologický senzor od LaskaKit kombinuje přesné senzory teploty, vlhkosti a tlaku – **SHT40** a **BMP280** s conformal coating z výroby a proto je mnohem odolnější vlhkému prostředí. Je ideální pro _venkovní měření počasí_, [meteostanice](https://www.laskakit.cz/laskakit-meteo-mini-meteostanice/?variantId=11915) nebo environmentální monitoring. Navrhli jsme tento sensor, protože plechové senzory **bme po několika měsíců provozu venku neměří vlhkost správné**.

Vybrat dobré, kvalitní a zároveň cenově dostupné čidlo pro měření teploty, vlhkosti a tlaku není úplně jednoduché. Právě s těmito požadavky v hlavě vznikl tento modul – praktické řešení, které spojuje vysokou přesnost, jednoduchost použití a nízkou spotřebu.

Na desce se nachází moderní **SHT40** od švýcarské firmy **Sensirion**, uzavřený v kompaktním pouzdře **DFN4**. Tento senzor vyniká přesností měření teploty a relativní vlhkosti, nízkým šumem a spolehlivostí i v náročných podmínkách. Dále je zde osazený i **BMP280** – osvědčený senzor od Bosch pro přesné měření **barometrického tlaku** a také doplňkové měření teploty. Modul tak pokrývá všechny základní meteorologické veličiny.

Součástí modulu jsou i **pull-up rezistory** pro I2C sběrnici a **blokovací kondenzátor**, který zajišťuje stabilní napájení. Celek je osazen v praktickém venkovním krytu s filtrem, vhodném pro montáž do meteostanic či jiných venkovních aplikací.

Díky speciálně navržené desce lze část se samotným čidlem odlomit a použít pro vestavbu do [krytu pro čidla](https://www.laskakit.cz/kryt-senzoru-s-kabelem--4pin--1m), nebo do jakéhokoli jiného vhodného krytu. Po odlomení již nejsou na desce I2C pullup rezistory a je nutné, aby je mělo zařízení, ke kterému se bude čidlo připojovat.

#### Refresh čidla SHT4x:

*   Před prvním spuštěním doporučujeme provést [refresh čidla](https://github.com/LaskaKit/Temp-HumSensor-SHTxx/tree/main/SW/sht4x_regeneration), aby se odstranila případná kontaminace a čidlo měřilo v rámci uvedených parametrů. Refresh spočívá v tom, že se spustí vnitřní vyhřívání čidla na teplotu cca 120°C po dobu cca 90min až měřená hodnota vlhkosti klesne na cca 5%RH. Tuto proceduru je lepší dělat v místnosti s vlhkostí cca 50%RH a teplotě cca 23°C. V závislosti na teplotě a vlhkosti v místnosti se může doba procedury lišit. K tomuto účelu jsme vytvořili program pro Arduino, kde je zapracováno spínání vnitřního topení a současné měření aktuální hodnoty vlhkosti. Při poklesu měřené vlhkosti na 5%RH se cyklus ukončí a přejde na standardní měření. Reálné hodnoty jsou pak k dispozici po vychladnutí čidla na teplotu okolí.
    
*   Tato procedura se může použít i v případě, že čidlo během doby přestane měřit správné hodnoty.
    

#### Klíčové vlastnosti

*   **Měření teploty** pomocí SHT40
    
*   **Relativní vlhkost**pomocí SHT40
    
*   **Atmosférický tlak** díky senzoru BMP280
    
*   Komunikace přes **I2C** sběrnici
    
*   **Připraveno k montáži** – Čidlo lze odlomit a použít pro vestavbu do [krytu pro čidla](https://www.laskakit.cz/kryt-senzoru-s-kabelem--4pin--1m)
    
*   Snadné připojení přes µŠup čtyřpinový konektor (STEMMA QT, Qwiic)
    
*   Nízká spotřeba – ideální pro bateriová zařízení
    

#### Specifikace:

*   Napájení: 1.8-3.6V DC - typicky 3.3V DC
    
*   Rozlišení: 16bit
    
*   SHT40:
    
    *   Provozní rozsah:
        
        *   Teplota: -40-125°C
            
        *   Vlhkost: 0-100% RH
            
    *   Rozlišení:
        
        *   Teplota: 0.01°C
            
        *   Vlhkost: 0.01 RH
            
    *   Přesnost:
        
        *   Teplota: ±0.2°C
            
        *   Vlhkost: ±1.8% RH
            
*   BMP280:
    
    *   Provozní rozsah:
        
        *   Tlak: 300-1100hPa
            
        *   Teplota: -40 až +85°C
            
    *   Rozlišení:
        
        *   Teplota: 0.01° C
            
        *   Tlak: 0.16Pa
            
    *   Přesnost:
        
        *   Teplota: ± 0.5°C
            
        *   Tlak: ± 1.7hPa
            
*   Rozměry: 26x19mm

## Produkt najdeš na https://www.laskakit.cz/laskakit-outdoor-meteo-thp-senzor-sht40-bmp280/
