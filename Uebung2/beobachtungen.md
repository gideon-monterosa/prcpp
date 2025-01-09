# Beobachtungen

## Screenshots

![42](./output/perlinNoise_42.pgm)

- imageWidth: 1000
- imageHeight: 1000
- cellSize: 20
- seed: 42

---

![7](./output/perlinNoise_7.pgm)

- imageWidth: 500
- imageHeight: 500
- cellSize: 10
- seed: 7

---

![123](./output/perlinNoise_123.pgm)

- imageWidth: 2000
- imageHeight: 200
- cellSize: 40
- seed: 123

---

![256](./output/perlinNoise_256.pgm)

- imageWidth: 1200
- imageHeight: 800
- cellSize: 24
- seed: 256

---

![99](./output/perlinNoise_99.pgm)

- imageWidth: 1000
- imageHeight: 1000
- cellSize: 20
- seed: 99

## Beobachtungen zur Gittergrösse und Interpolationsfunktionen

Gittergrösse: Kleinere Gitter (z.B. 10 Pixel) erzeugen detailliertere und
komplexere Muster, während grössere Gitter (z.B. 40 Pixel) glattere und
einfachere Muster schaffen. Zu grosse Zellen können das Rauschen monoton wirken
lassen.

Interpolationsfunktionen: Die Wahl der Interpolation beeinflusst die Übergänge
zwischen den Zellen. Lineare Interpolation führt zu abrupten Übergängen und
sichtbaren Kanten. Glattere Methoden wie kubische Fade-Funktionen sorgen für
sanfte Übergänge und ein natürlicheres Rauschen.

Kombinierte Effekte: Kleine Gittergrössen mit glatter Interpolation ergeben
detaillierte Muster. Grössere Gittergrössen mit einfacher Interpolation eignen
sich für einfachere Grafiken.
