## Zadanie 3.

### Treść zadania

Zaimplementować dwu wymiarowe pudełko ze zderzającymi się kulkami(okręgami). Okręgi o różnym rozmiarze i poruszające się z różnymi prędkościami.
Zadanie to można podzielić na kilka etapów (lub wykonać jako jeden, w zależności od umiejętności).

W pierwszym etapie można skupić się na samym zagadnieniu definicji potrzebnych struktur. Jeśli wybrali Państwo język programowania umożliwiający definiowanie takich a zapewne tak będzie (a prawdopodobnie będą Państwo bazowali na jakimś z podejściem obiektowym 99% czy też funkcyjnym to wspierają).

Sugeruje zbudowanie struktury przechowującej informacje o położeniu kulki (X,Y), jej prędkości (Vx, Vy), (opcjonalnie wielkości, masie). Można pokusić się o wykorzystanie operacji na wektorach (część języków wspiera z automatu, pozostałe mają „biblioteki”, napisanie takich klas tj. WEKTOR z podstawowymi operacjami, bez optymalizacji to też raczej błahostka). W pierwszym podejściu można przyjąć, że kulki się tylko poruszają np. w lewo i w górę. Jeśli to działa można przejść do etapu dobijania się od krawędzi (bez odbijania się wzajemnego, przechodzą na razie „przez siebie”).

W następnym etapie można wykrywać kolizję (znów proste równanie a właściwie porównanie promieni z odległością środków, każdy z każdym)

Możliwy jest tu półkrok (nie był przewidywany, wynika z praktyki oddawanych projektów). Możliwość implementacji „naiwnych” odbić, czyli pop prostu zamiany kierunków Vx, Vy. Sugeruję jednak zastosować zwykłe rozwiązanie !!!

W końcowym etapie można zaimplementować fizykę zderzeń, najlepszym podejściem (tylko propozycja !?) jest tu rozpatrywanie środka mas dwóch zderzających się kulek. Zagadnienie można uprościć do mas równych jeden.


### Opis rozwiązania
