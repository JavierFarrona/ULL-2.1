/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 4
 *
 * @author Esther M. Quintero (alu0101434780@ull.edu.es)
 * @date 23 Oct 2022
 * @brief Archivo: counter.h
 *        Definición de la clase "counter"
 * 
 * @details 
 *    23/10/2022 - Creación del fichero
 *    23/10/2022 - Añadida la clase "counter"
 */

/** 
 *  @brief Esta clase se usa para guardar cantidades de elementos
 *         que encontremos mientras analizamos el fichero.
 *         Guarda los siguientes datos:
 *            - Cantidad de bucles (for_loops_, while_loops_)
 *            - Cantidad de comentarios (multi_comments_, normal_comments_)
 *            - Cantidad de variables (int_variables_, double_variables_)
 */
class Counter {
 private:
  int for_loops_;
  int while_loops_;
  int multi_comments_;
  int normal_comments_;
  int int_variables_;
  int double_variables_;

 public:
  /// Constructor (no recibe nada)
  Counter();

  /// Getters
  int get_for_count() const { return for_loops_; };
  int get_while_count() const { return while_loops_; };
  int get_multi_comments_count() const { return multi_comments_; };
  int get_normal_comments_count() const { return normal_comments_; };
  int get_int_count() const { return int_variables_; };
  int get_double_count() const { return double_variables_; };

  /// Funciones
  void add_for() { ++for_loops_; };
  void add_while() { ++while_loops_; };
  void add_multi_comment() { ++multi_comments_; };
  void add_normal_comment() { ++normal_comments_; };
  void add_int() { ++int_variables_; };
  void add_double() { ++double_variables_; };
}; 