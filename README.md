# CSE 3206 – Lab 3: Iterator and Mediator Design Patterns

**Course:** CSE 3206 – Software Engineering Sessional, Dept. of CSE, RUET
**Lab 3:** Design Pattern Analysis, Implementation and Code Review
**Group 07 – Section C (1st 30)**

| Name | Student ID | GitHub | Work in this repo | Branch |
|---|---|---|---|---|
| Abdullah Al Kafi | 2203139 | [@Kafi2611](https://github.com/Kafi2611) | Repository setup, README, both "without pattern" codes, UML diagrams, report, code review | `main`, `kafi-diagrams-report` |
| Sadaf Rahman | 2203140 | [@sadaf532](https://github.com/sadaf532) | Iterator Pattern code (`iterator.cpp`) | `sadaf-iterator` |
| Sakila Akter | 2203141 | [@SakilaAkter](https://github.com/SakilaAkter) | Mediator Pattern code (`mediator.cpp`) | `sakila-mediator` |

Each member worked on a separate branch and opened a pull request. Kafi reviewed the code (see [`Code_Review.md`](Code_Review.md)) and merged it into `main`.

## Patterns and examples

| Pattern | Category | Example |
|---|---|---|
| Iterator | Behavioral | **RUET cafeteria menu** – one `printMenu()` prints a Breakfast Menu (array) and a Lunch Menu (vector) using only `hasNext()` and `next()`. |
| Mediator | Behavioral | **Group chat room** – Kafi, Sadaf and Sakila send messages through a `ChatRoom`; users never talk to each other directly. |

For each pattern there are two programs: one **without** the pattern (the problem) and one **with** the pattern (the solution).

## Folder structure

```
CSE3206-Lab3-Iterator-Mediator/
├── Iterator/
│   ├── without_iterator.cpp   # Code 1 (the problem)
│   └── iterator.cpp           # Code 2 (with Iterator Pattern)
├── Mediator/
│   ├── without_mediator.cpp   # Code 3 (the problem)
│   └── mediator.cpp           # Code 4 (with Mediator Pattern)
├── Diagrams/                  # UML class and sequence diagrams (PNG)
├── Report/                    # lab report
├── Code_Review.md             # code review of iterator.cpp and mediator.cpp
├── .gitignore                 # files Git should not upload (.exe etc.)
└── README.md
```

## How to compile and run

Needs any C++11 (or newer) compiler, for example g++.

```bash
# Iterator
g++ Iterator/iterator.cpp -o iterator
./iterator            # on Windows: iterator.exe

# Mediator
g++ Mediator/mediator.cpp -o mediator
./mediator            # on Windows: mediator.exe
```

### Expected output

`iterator.cpp`
```
Breakfast Menu:
  - Paratha
  - Egg Bhaji
  - Tea
Lunch Menu:
  - Rice
  - Chicken Curry
  - Dal
```

`mediator.cpp`
```
Kafi sends: Lab report is ready!
   Sadaf got from Kafi: Lab report is ready!
   Sakila got from Kafi: Lab report is ready!
Sadaf sends: Great, I will check the code.
   Kafi got from Sadaf: Great, I will check the code.
   Sakila got from Sadaf: Great, I will check the code.
```

## Diagrams

| | |
|---|---|
| Iterator – class diagram | `Diagrams/iterator_class_diagram.png` |
| Iterator – sequence diagram | `Diagrams/iterator_sequence_diagram.png` |
| Iterator – without vs with | `Diagrams/iterator_without_vs_with.png` |
| Mediator – class diagram | `Diagrams/mediator_class_diagram.png` |
| Mediator – sequence diagram | `Diagrams/mediator_sequence_diagram.png` |
| Mediator – without vs with | `Diagrams/mediator_without_vs_with.png` |
| Git workflow | `Diagrams/git_workflow.png` |
| Our branches | `Diagrams/git_branches.png` |
