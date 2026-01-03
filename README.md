# Arduino Reaction Game

Un joc interactiv pentru testarea reflexelor, construit pe platforma Arduino. Proiectul include un meniu de selectie, efecte sonore si doua moduri de joc distincte pentru a-ti pune viteza la incercare.

---

## Moduri de Joc

Sistemul permite selectarea modului de joc folosind un comutator (Switch) conectat la pinul 12.

### 1. Viteza 10 (Time Trial)
* **Obiectiv:** Trebuie sa apesi butonul corect pentru 10 runde consecutive.
* **Dinamica:** Cronometrul porneste la prima runda. La final, primesti timpul total in secunde.

### 2. Reactie Contra Timp (Survival)
* **Obiectiv:** Rezista cat mai multe runde fara sa gresesti si fara sa depasesti timpul limita.
* **Dinamica:** Timpul de reactie scade progresiv (jocul devine mai rapid) cu fiecare runda castigata.
* **Fail:** Daca apesi gresit sau esti prea lent, jocul se termina.

---

## Componente Necesare

|   |   |   |
| :---: | --- | --- |
| **Arduino Uno** | Sau orice placa compatibila |
| **Butoane Push** | Pentru input joc |
| **LED-uri** | Culori diferite (ex: Rosu, Galben, Verde) |
| **Rezistente** | 220 Ohm (pentru LED-uri) |
| **Buzzer** | Pasiv (pentru sunete) |
| **Switch / Buton** | Pentru schimbarea modului de joc |
| **Fire & Breadboard** | Pentru conexiuni |

---

## Schema de Conexiuni (Pinout)

Configuratia foloseste modul **INPUT_PULLUP** pentru butoane (nu necesita rezistente externe pe butoane), iar LED-urile au rezistenta montata spre GND.

| Componenta | Pin Arduino | Configuratie |
| :--- | :---: | :--- |
| **Buton Stanga** | `D2` | Un pin la Arduino <--> Un pin la GND |
| **Buton Mijloc** | `D3` | Un pin la Arduino <--> Un pin la GND |
| **Buton Dreapta** | `D4` | Un pin la Arduino <--> Un pin la GND |
| **LED Stanga** | `D8` | Pin Arduino (+) <--> LED <--> Rezistenta <--> GND |
| **LED Mijloc** | `D9` | Pin Arduino (+) <--> LED <--> Rezistenta <--> GND |
| **LED Dreapta** | `D10` | Pin Arduino (+) <--> LED <--> Rezistenta <--> GND |
| **Buzzer** | `D11` | Pin Arduino (+) <--> Buzzer <--> GND |
| **Switch Mod** | `D12` | Un pin la Arduino <--> Un pin la GND |

> **Nota:** Pentru LED-uri, piciorul lung (Anod) merge spre Pinul Arduino, iar piciorul scurt (Catod) merge spre rezistenta si apoi la GND.

---


### Poza Montaj
![Montaj Arduino](poza.jpeg)



## Instalare si Utilizare

1. **Hardware:** Realizeaza conexiunile conform tabelului de mai sus.
2. **Software:**
    * Deschide `Arduino IDE`.
    * Copiaza codul din fisierul `.ino` al acestui repo.
    * Selecteaza placa si portul corect.
    * Apasa **Upload**.
3. **Play:**
    * Deschide **Serial Monitor** (Baud Rate: `9600`) pentru a vedea timpii si mesajele.
    * Selecteaza modul dorit din Switch (LED-urile vor clipi pentru confirmare).
    * Apasa orice buton de joc (D2, D3 sau D4) pentru a incepe!

---

## Licenta

Acest proiect este open-source. Poti sa-l modifici si sa-l imbunatatesti cum doresti.