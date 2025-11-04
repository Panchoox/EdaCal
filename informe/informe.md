# Informe del Proyecto EdaCal

## 1. Introducción

### 1.1 Objetivo del Proyecto
El proyecto EdaCal tiene como objetivo desarrollar una calculadora de expresiones aritméticas que utiliza estructuras de datos fundamentales para evaluar y convertir expresiones matemáticas entre diferentes notaciones (infija, prefija y postfija).

### 1.2 Alcance
- Implementación de estructuras de datos básicas (lista enlazada, pila, árbol)
- Evaluación de expresiones aritméticas
- Conversión entre notaciones
- Interfaz de línea de comandos

## 2. Estructuras de Datos

### 2.1 Node (Nodo)
Estructura genérica que representa un nodo con:
- Datos de tipo genérico `T`
- Puntero al siguiente nodo
- Utilizado como base para listas enlazadas

### 2.2 LinkedList (Lista Enlazada)
Lista enlazada simple que permite:
- Inserción y eliminación al inicio y al final
- Acceso a elementos
- Gestión de memoria dinámica

### 2.3 Stack (Pila)
Estructura LIFO (Last In First Out) implementada usando lista enlazada:
- Operaciones push y pop
- Consulta del elemento superior (top)
- Utilizada para evaluación de expresiones

### 2.4 ExpressionTree (Árbol de Expresiones)
Árbol binario para representar expresiones:
- TreeNode: nodo del árbol con valor y dos hijos
- ExpressionTree: árbol completo con operaciones de construcción y evaluación
- Permite representar la precedencia de operadores

## 3. Componentes Principales

### 3.1 Calculator
Clase principal que coordina:
- Evaluación de expresiones en diferentes notaciones
- Conversión entre notaciones
- Validación de expresiones

### 3.2 Utils
Funciones utilitarias para:
- Procesamiento de cadenas
- Validación de caracteres
- Conversiones de tipos

## 4. Notaciones de Expresiones

### 4.1 Notación Infija
- Forma estándar: `a + b`
- Operador entre operandos
- Requiere paréntesis para precedencia

### 4.2 Notación Prefija (Polaca)
- Operador antes de operandos: `+ a b`
- No requiere paréntesis
- Evaluación de derecha a izquierda

### 4.3 Notación Postfija (Polaca Inversa)
- Operador después de operandos: `a b +`
- No requiere paréntesis
- Evaluación de izquierda a derecha
- Más eficiente para evaluación

## 5. Algoritmos

### 5.1 Conversión Infija a Postfija
Algoritmo de Shunting Yard:
1. Usar una pila para operadores
2. Salida directa de operandos
3. Gestionar precedencia y paréntesis

### 5.2 Evaluación de Expresiones Postfijas
1. Usar una pila para operandos
2. Al encontrar operador, extraer operandos
3. Realizar operación y apilar resultado

### 5.3 Construcción del Árbol de Expresiones
1. Parsear expresión
2. Construir árbol según precedencia
3. Nodos internos: operadores
4. Hojas: operandos

## 6. Pruebas

### 6.1 Pruebas Unitarias
- test_linked_list.cpp: Pruebas de lista enlazada
- test_stack.cpp: Pruebas de pila
- test_tree.cpp: Pruebas de árbol de expresiones
- test_calculator.cpp: Pruebas de calculadora

### 6.2 Casos de Prueba
TODO: Definir casos de prueba específicos

## 7. Compilación y Ejecución

### 7.1 Sistema de Compilación
- CMake para gestión del proyecto
- Compilación con C++17
- Generación de ejecutables de prueba

### 7.2 Instrucciones
```bash
mkdir build && cd build
cmake ..
make
./edacal
ctest  # Para ejecutar pruebas
```

## 8. Estado del Proyecto

### 8.1 Completado
- ✅ Estructura del proyecto
- ✅ Definición de clases y métodos
- ✅ Sistema de compilación
- ✅ Esqueleto de pruebas

### 8.2 Pendiente
- ⏳ Implementación de métodos de estructuras de datos
- ⏳ Implementación de algoritmos de conversión
- ⏳ Implementación de evaluación de expresiones
- ⏳ Pruebas completas
- ⏳ Documentación detallada

## 9. Conclusiones

El proyecto EdaCal proporciona una base sólida para la implementación de una calculadora de expresiones utilizando estructuras de datos fundamentales. La arquitectura modular facilita el desarrollo incremental y las pruebas.

## 10. Referencias

- Algoritmos y Estructuras de Datos
- Notación Polaca y Polaca Inversa
- Árboles de Expresiones
- Algoritmo de Shunting Yard
