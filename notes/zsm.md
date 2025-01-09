# Zusammenfassung

## friend Operator

Ohne friend wird beim Operator overloading ein versteckter pointer auf this
übergeben. Mit friend wird dieser nicht übergeben dafür wird lhs und rhs
übergeben (z.B. beim + Operator der zwei Argumente erwartet).

```cpp

  // Variante 1
  Point operator+(const Point& other) {}

  // Variante 2
  friend Point operator+(const Point& lhs, const Point& rhs) {}

```

Der Vorteil von Variante 2 ist das dieser flexibler aufgerufen werden kann.
Variante erwartet auf der linken Seite einen Point (asymetrisch). Variante 2
kann aufgerufen werden auch wenn auf der linken Seite ein Punkt ist (sofern der
entsprechende Constructor existiert).

## Operatoren nicht doppelt implementieren

In der Implementation vom `+` Operator kann der bereits implementierte `+=`
Operator verwendet werden.

```cpp
friend Point operator+(Point lhs, const Point& rhs) {
  return lhs += rhs;
}
```

lhs wird by value und nicht als Referenz übergeben also kann `+=` verwendet
werden um die Summe zu berechnen (dabei wird die Kopie von lhs mutiert und
zurückgegeben). Übergebe ich lhs als Referenz dann muss zuerst der Kopie
Constructor aufgerufen werden.

## Objektkopien verhindern

Durch das übergeben von r values (mit &&) kann verhindert werden, dass temporäre
Objekte unnötig kopiert werden.

```cpp
friend Point operator+(Point&& lhs, const Point& rhs) {
  return lhs += rhs;
}

friend Point operator+(const Point& lhs, Point&& rhs) {
  return rhs += lhs;
}
```

Die erste Variante verhindert das im falle eines temporären object links dieses
Kopiert wird und Variante 2 das gleiche umgekehrt. Das Ergebnis des Addition in
den Klammern liefert jeweils ein temporäres Objekt zurück.

```cpp
// Variante 1
(p1 + p2) + p3

// Variante 2
p1 + (p2 + p3)
```

## To String bei Vererbung

```cpp
friend std::ostream& operator<<(std::ostream& os, const Student& s) {
  os << static_cast<const Person&>(s)
     << ", Studenten Nummer: "
     << s.getStudentNumber();
  return os;
}
```

## Childs in einer Liste speichern

Bei einer Vektor werden alle als Personen gespeichert, es sind also keine
Studenten mehr. Wir können auch keinen Array oder Vektor mit mit Referenzen auf
die Personen erstellen. dynamic_pointer_cast aufrufen und mit einem if zu
arbeiten ist sehr unschön.

```cpp
Person p1("Peter", 21);
Person p2("Marius", 22);
Student s1("Robert", 23, 123);
Student s2("Markus", 24, 321);

std::vector<std::shared_ptr<Person>> persons {
    std::make_shared<Person>(p1),
    std::make_shared<Person>(p2),
    std::make_shared<Student>(s1),
    std::make_shared<Student>(s2)
};

for (auto p : persons) {
    auto s = dynamic_pointer_cast<Student>(p);
    p->print(std::cout);
    std::cout << std::endl;
}
```

`dynamic_cast` für einen Pointer heisst `dynamic_pointer_cast`

Damit der Code oben funktioniert muss die polimorphe Funktion print() sowohl in
Person als auch in Student implementiert sein.

```cpp
// Person

virtual void print(std::ostream& os) {
  os << *this;
}

// Student
void print(std::ostream& os) override {
  os << *this;
}
```

## Polymorphie für eine Klasse einschalten

Damit wir zur Laufzeit den Typ eines Objektes abfragen können müssen wir
zusätzlich sogenannte RTTI abspeichern (Run Time Type Information).

Diesen Vorgang können wir einschalten indem wir eine Methode als `virtual`
definieren. Normalerweise stellt man den Destruktor auf virtual da dieser nicht
virtual sein kann.

Grundsätzlich ist es sinnvoll dies auf der eigenen Klasse und auf dem Child zu
setzen.

Wenn die Basisklasse Polymorphie unterstützt, wird auch die Abgeleitete Klasse
auch Polymorphie unterstützen.

## Abstracte Methoden

In der Abstraken Klasse die Methode als `= 0` deklarieren.

## Kategorien von ausdrücken

- l-value: Speicheradresse, referenzierbar, veränderbar. (hat identität)
- r-value: Temporärer Wert, nicht veränderbar, kein fester Speicherort. (keine
  identität)
- x-value: Temporärer, verschiebbarer Wert kurz vor seiner Zerstörung. (hat
  identität)

identität bedeutet, dass ein Objekt an einer bestimmten Speicheradresse
existiert. Ein Literal (z.B. `5`) hat keine Adresse im Speicher und deswegen
auch keine Idendität. Ein temporäres Object, welches in einer Funktion erstellt
und zurückgegeben wird (x-value) hat identität. Mit diesem Mechanismus wird
Return-Value-Otimization (RVO) implementiert.

## Return Value Optimization
