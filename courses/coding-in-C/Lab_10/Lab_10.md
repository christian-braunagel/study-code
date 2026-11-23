# Lab 10: Empirische Analyse von Sortieralgorithmen

## Introduction

Ziel dieses Labors ist es, das Zusammenspiel von **theoretischer Komplexitätsanalyse** und **empirischer Laufzeitmessung** zu verstehen. Dazu implementieren Sie zwei bekannte Sortieralgorithmen in C und vergleichen deren Verhalten anhand zufällig erzeugter Eingabedaten unterschiedlicher Größe.

Der Fokus liegt nicht nur auf der Implementierung, sondern insbesondere auf:
- systematischer Messung von Laufzeiten,
- statistischer Auswertung der Messergebnisse,
- und dem Abgleich von Praxis und Theorie mittels Landau-Notation.

All the following sections of this lab are based on the following levels of dificulty:

🟢 __Simple__: A simple coding task that usually guides you step by step through the process and focuses on learning the basics. It should not take more than 15min to finish it.

🟡 __Moderate__: A coding task that usually states a moderate problem to test your understanding and transfer skills from syntax to real-world applications. These tasks can be solved in about 30mins depending on your knowledge.

🔴 __Complex__: Quite a difficult or lengthy coding task that requires you to use the acquired knowledge of the previous tasks in a broader context or project. Such tasks might take up to a few hours to solve them.

---

## 🔴 Section I

### Task Description

Implementieren Sie ein C-Programm, das:

1. zwei Sortieralgorithmen implementiert:
   - **Insertion Sort**
   - **Quicksort**
2. zufällige Ganzzahllisten erzeugt:
   - zufällige Länge `n`
   - zufällige Werte innerhalb eines geeigneten Bereichs
3. beide Algorithmen auf identischen Kopien der Liste ausführt
4. die Laufzeit jedes Algorithmus misst
5. die Messungen für verschiedene Listenlängen wiederholt
6. die Ergebnisse speichert und auswertet

---

### Requirements

Ihr Programm soll:

1. eine Funktion zur Erzeugung einer Liste mit zufälliger Länge und zufälligen Werten enthalten
2. Insertion Sort in einer eigenen Funktion implementieren
3. Quicksort in einer eigenen Funktion implementieren
4. sicherstellen, dass beide Algorithmen jeweils **dieselbe Eingabe** erhalten (Kopien der Liste)
5. die Laufzeit der Sortieralgorithmen messen (z. B. mit `clock()` oder `clock_gettime`)
6. für jede Listenlänge `n` **mehrere Durchläufe** durchführen
7. für jede Kombination aus Algorithmus und `n`:
   - den **Mittelwert**
   - den **Median**
   der gemessenen Laufzeiten berechnen
8. die Ergebnisse in strukturierter Form ausgeben (z. B. tabellarisch)

---

### Notes

- Wählen Sie die Werte für `n` so, dass Unterschiede im Laufzeitverhalten sichtbar werden.
- Verwenden Sie eine geeignete Anzahl an Wiederholungen pro `n`, um Messrauschen zu reduzieren.
- Achten Sie darauf, dass Compiler-Optimierungen die Vergleichbarkeit nicht verfälschen.

---

## 🟡 Section II: Empirische Auswertung

Analysieren Sie die gemessenen Laufzeiten:

1. Vergleichen Sie Insertion Sort und Quicksort für unterschiedliche Werte von `n`.
2. Untersuchen Sie, ab welcher Listenlänge sich deutliche Unterschiede im Laufzeitverhalten zeigen.
3. Diskutieren Sie die Streuung der Messwerte sowie Unterschiede zwischen Mittelwert und Median.
4. Identifizieren Sie mögliche Ursachen für Ausreißer oder unerwartete Messergebnisse.

---

## 🔴 Section III: Theoretische Analyse

Leiten Sie die **asymptotische Laufzeit** beider Algorithmen theoretisch her:

1. Bestimmen Sie die Laufzeit von Insertion Sort in:
   - Best Case
   - Average Case
   - Worst Case
2. Bestimmen Sie die Laufzeit von Quicksort in:
   - Best Case
   - Average Case
   - Worst Case
3. Verwenden Sie hierfür die **Landau-Notation** (`O`, `Θ`, `Ω`).

---

## 🟡 Section IV: Diskussion

Vergleichen Sie die empirischen Ergebnisse mit der theoretischen Analyse:

1. Stimmen die gemessenen Laufzeiten mit den erwarteten asymptotischen Verläufen überein?
2. Wo weichen Theorie und Praxis voneinander ab?
3. Welche Rolle spielen konstante Faktoren, Cache-Effekte oder Implementierungsdetails?
4. Warum ist die asymptotische Analyse dennoch ein wichtiges Werkzeug zur Bewertung von Algorithmen?

---

## Deliverables

Abzugeben sind:

1. der vollständige C-Quellcode
2. eine kurze schriftliche Auswertung (z. B. als PDF oder Markdown), die:
   - die Messergebnisse zusammenfasst
   - die theoretische Analyse darstellt
   - die Abweichungen zwischen Theorie und Praxis diskutiert
