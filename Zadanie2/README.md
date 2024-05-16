## Zadanie 2.

### Treść zadania
1) Utwórz program, który potrafi załadować bitmapę i wyrysować jej ściętą wersje (sam
zaimplementuj proces ścinania).
2) Animacja duszka na ekranie (można wykorzystać poprzednią pracę tak aby animując się
odbijał). Dołożyć tło. Animacja w klimacie gier typu "super mario", czyli zrobić sterowanie
myszą postaci, dodać 2-3 dodatkowe duszki (bez zderzeń), przewijać tło (na tym etapie
może być "nawinięte na walcu").

### Rozwiązanie
Po naciśnięciu przycisku "Start" wyświetla nam się poniższy widok:

![Start](grafiki/screen1.png) 

**Sterowanie strzałkami:**
- Prawo: Bohater biegnie w prawo; tło przesuwa się w lewo
- Lewo: Bohater biegnie w lewo; tło przesuwa się w prawo
- Góra: Bohater odwraca się tyłem; tło nie przesuwa się
- Dół: Bohater odwraca się przodem; tło nie przsuwa się

![Biegnij](grafiki/screen2.png)

**Lot ptaka:**
Ptak lata od jednego do drugiego końca ekranu. Zwalnia, gdy porusza się w tym samym kierunku co bohater, przyśpiesza, gdy w przeciwnym.

