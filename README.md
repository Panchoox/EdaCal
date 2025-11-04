# EdaCal - Calculadora de Expresiones

## Descripción

EdaCal es una calculadora de expresiones aritméticas que implementa estructuras de datos fundamentales (listas enlazadas, pilas, árboles) para evaluar y convertir expresiones matemáticas entre diferentes notaciones.

## Características

- Evaluación de expresiones en notación infija, prefija y postfija
- Conversión entre diferentes notaciones
- Implementación de estructuras de datos desde cero:
  - Lista enlazada simple
  - Pila (LIFO)
  - Árbol de expresiones
- Utilidades para procesamiento de cadenas

## Estructura del Proyecto

```
EdaCal/
├── include/eda/          # Archivos de cabecera
│   ├── node.hpp
│   ├── linked_list.hpp
│   ├── stack.hpp
│   ├── expression_tree.hpp
│   ├── calculator.hpp
│   └── utils.hpp
├── src/                  # Implementaciones
│   ├── node.cpp
│   ├── linked_list.cpp
│   ├── stack.cpp
│   ├── expression_tree.cpp
│   ├── calculator.cpp
│   └── utils.cpp
├── tests/                # Pruebas unitarias
│   ├── test_linked_list.cpp
│   ├── test_stack.cpp
│   ├── test_tree.cpp
│   └── test_calculator.cpp
├── informe/              # Documentación del proyecto
├── main.cpp              # Programa principal
├── CMakeLists.txt        # Configuración de CMake
└── README.md
```

## Compilación

### Requisitos

- CMake 3.10 o superior
- Compilador con soporte C++17 (g++, clang++)

### Instrucciones

```bash
# Crear directorio de compilación
mkdir build
cd build

# Configurar el proyecto
cmake ..

# Compilar
make

# Ejecutar el programa principal
./edacal

# Ejecutar las pruebas
ctest
```

## Uso

El programa principal ofrece un menú interactivo con las siguientes opciones:

1. Evaluar expresión infija
2. Evaluar expresión postfija
3. Evaluar expresión prefija
4. Convertir infija a postfija
5. Convertir infija a prefija
6. Convertir postfija a infija
7. Convertir prefija a infija

### Ejemplo de uso

```
=== EdaCal - Calculadora de Expresiones ===
1. Evaluar expresión infija
2. Evaluar expresión postfija
...
Seleccione una opción: 1
Ingrese expresión infija: 3 + 4 * 2
Resultado: 11
```

## Desarrollo

Este proyecto está en fase de desarrollo. Las estructuras y métodos están definidos pero pendientes de implementación completa.

### Estado actual

- ✅ Estructura del proyecto creada
- ✅ Archivos de cabecera definidos
- ✅ Esqueletos de implementación
- ✅ Sistema de compilación con CMake
- ✅ Pruebas unitarias básicas
- ⏳ Implementación de lógica pendiente

## Licencia

Proyecto educativo para el curso de Estructuras de Datos y Algoritmos.