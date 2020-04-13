# Explicación de las funciones del parcial 2

---

## 1. crearCentroComercial

-Entradas: La función recibe el número de pisos del centro comercial y el número de locales por piso.

-Salidas: La matriz del centro comercial

-Conceptos usados: Memoria dinamica puesto que la matriz se crea a partir de valores dados por el usuario.

## 2. aniadirLocal

-Entradas: Recibe la matriz del centro comercial, el piso y el número de local en el que se añade el local,
el nombre del local y la cantidad de empleados del mismo.

-Salidas: Ninguna.

-Conceptos usados: Paso de parametros por referencia puesto que así se pasa la matriz, así como paso de parametros por valor para los otros datos, también se hace uso de la función strcpy que permite copiar el nombre del local dentro del struct.

## 3. freeCentroComercial

-Entradas: Recibe la matriz del centro comercial, y el número de pisos del centro comercial.

-Salidas: Ninguna.

-Conceptos usados: Paso de parametros por referencia para pasar la matriz, así como paso de parametros por valor para las otras variables, se hace uso de la función free para liberar la memoria que ocupa la matriz.

## 4. buscarNombre

-Entradas: Recibe la matriz del centro comercial, el número de pisos y de locales por piso del centro comercial así como también el nombre del local a buscar.

-Salidas: Ninguna.

-Conceptos usados: Paso de parametros por referencia puesto que así se pasa la matriz, así como paso de parametros por valor para los otros datos, se hace uso de strcmp para comparar los nombres de la matriz y del parametro 'nombre' para encontrar el nombre del local.

## 5. buscarPiso

-Entradas: Recibe la matriz del centro comercial, el número de pisos y de locales por piso del centro comercial así como también el piso en el que se buscaran los locales.

-Salidas: Ninguna.

-Conceptos usados: Paso de parametros por referencia puesto que así se pasa la matriz, así como paso de parametros por valor para los otros datos, se hace uso de enums para comparar el estado del struct e identificar si está ocupado o libre.

## 6. modificarEmpleados

-Entradas: Recibe la matriz del centro comercial, el número de pisos y de locales por piso del centro comercial así como también el nombre del local a modificar y la opción escogida para diferenciar si se contrata o se despide a un empleado.

-Salidas: Ninguna.

-Conceptos usados: Paso de parametros por referencia puesto que así se pasa la matriz, así como paso de parametros por valor para las demás variables, se usa strcmp para identificar el local correcto y de enums para saber si el local está libre u ocupado.

## 7. eliminarLocal

-Entradas: Recibe la matriz del centro comercial, el número de pisos y de locales por piso del centro comercial así como también el nombre del local a eliminar.

-Salidas: Ninguna.

-Conceptos usados: Paso de parametros por referencia puesto que así se pasa la matriz, así como paso de parametros por valor para las demás variables, se usa strcmp para identificar el local que pide el usuario y de enums para saber si el local está libre u ocupado, y luego para cambiar el estado de ocupado a libre.

## 8. totalEmpleados

-Entradas: Recibe la matriz del centro comercial, el piso a calcular el total de empleados y el número de locales por piso del centro comercial.

-Salidas: El total de empleados del piso dado por el usuario.

-Conceptos usados: Paso de parametros por referencia puesto que así se pasa la matriz, así como paso de parametros por valor para las demás variables, se hace uso de recursión para calcula la suma de todos los empleados del piso dado.
