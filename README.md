# OOP_MAI_LAB3
My third OOP lab in MAI third semester

## 📝 Описание проекта

Лабораторная работа №3 по ООП: реализация иерархии геометрических фигур с использованием:
- Абстрактных классов и полиморфизма
- Динамических массивов (векторов)
- Вычисления площади через формулу Гаусса
- Google Test для модульного тестирования

### Реализованные фигуры:
- **Rectangle** (Прямоугольник)
- **Rhombus** (Ромб)
- **Trapezoid** (Трапеция)

## 🛠️ Сборка проекта

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## 🚀 Запуск

### Основная программа:
```bash
./geometry_figures
```

### Тесты:
```bash
./run_tests
```

## 📂 Структура проекта

```
OOP_MAI_LAB3/
├── include/           # Заголовочные файлы
│   ├── figure.h
│   ├── point.h
│   ├── rectangle.h
│   ├── rhombus.h
│   ├── trapezoid.h
│   ├── vector-points.h
│   └── vector-figure.h
├── src/               # Исходные файлы
│   ├── main.cpp
│   ├── figure.cpp
│   ├── point.cpp
│   ├── rectangle.cpp
│   ├── rhombus.cpp
│   ├── trapezoid.cpp
│   ├── vector-points.cpp
│   └── vector-figure.cpp
├── test/              # Тесты Google Test
│   ├── main_test.cpp
│   ├── test_point.cpp
│   ├── test_figures.cpp
│   └── test_vectors.cpp
├── CMakeLists.txt
└── README.md
```

## 🧪 Тесты

Проект включает 19 модульных тестов для:
- ✅ Point (конструкторы, операторы сравнения)
- ✅ VectorPoints (добавление, удаление, доступ)
- ✅ VectorFigure (полиморфный контейнер, erase)
- ✅ Rectangle, Rhombus, Trapezoid (вычисление площади и центра)

### Запуск тестов:
```bash
cd build
./run_tests                          # Все тесты
./run_tests --gtest_filter=Point*    # Только тесты Point
./run_tests --gtest_filter=*Area*    # Только тесты площади
```

## 📐 Математика

Площадь многоугольника вычисляется по **формуле Гаусса** (Shoelace formula):

$$A = \frac{1}{2} \left| \sum_{i=0}^{n-1} (x_i \cdot y_{i+1} - x_{i+1} \cdot y_i) \right|$$

Работает для любых выпуклых и невыпуклых многоугольников

## 💡 Как работает программа

При запуске программы:

1. **Ввод количества фигур**
   ```
   INPUT VECTOR SIZE: 3
   ```

2. **Выбор типа фигуры и ввод координат** (повторяется для каждой фигуры)
   ```
   1 - Rectangle
   2 - Rhombus
   3 - Trapezoid
   
   1
   0 0 4 0 4 3 0 3
   ```

3. **Удаление фигуры по индексу**
   ```
   INPUT ERASE INDEX: 1
   ```

4. **Вывод площадей оставшихся фигур**
   ```
   2
   12.00
   12.00
   ```

## 🎓 Автор

FlyingVoodoo МАИ, 3 семестр  
Лабораторная работа №3 по ООП

