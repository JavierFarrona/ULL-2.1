/// Programa para probar la clase "NFA"

#include <iostream>
#include <string>

#include "NFA.cc"

int main() {
  /// Cremos el NFA vacío
  NFA nfa;

  /// Creamos el alfabeto
  std::string alfabeto = "01";
  Alphabet alphabet(alfabeto);
  nfa.setAlphabet(alphabet);
  // std::cout << alphabet << std::endl;
  
  Symbol symbol_0 = '0';
  Symbol symbol_1 = '1';

  /// Creamos los estados
  std::set<State> states;
  std::set<State> finals;
  /// Estado q0
    State state0;
    state0.setName("q0");
    state0.setID(0);
    states.insert(state0);
    nfa.setInitial(state0);
  /// Estado q1
    State state1;
    state1.setName("q1");
    state1.setID(1);
    states.insert(state1);
  /// Estado q2
    State state2;
    state2.setName("q2");
    state2.setID(2);
    states.insert(state2);
  /// Estado q3
    State state3;
    state3.setName("q3");
    state3.setID(3);
    state3.setFinal(true);
    states.insert(state3);
    finals.insert(state3);
  
  /// Creamos las transiciones
  std::set<Transition> transitions;
  /// q0
  Transition transition0(symbol_0, state0, state0);
  Transition transition1(symbol_1, state0, state0);
  Transition transition2(symbol_1, state0, state1);
  /// q1
  Transition transition3(symbol_0, state1, state2);
  Transition transition4(symbol_1, state1, state2);
  /// q2
  Transition transition5(symbol_0, state2, state3);
  Transition transition6(symbol_1, state2, state3);

  transitions.insert(transition0);
  transitions.insert(transition1);
  transitions.insert(transition2);
  transitions.insert(transition3);
  transitions.insert(transition4);
  transitions.insert(transition5);
  transitions.insert(transition6);

  nfa.setStates(states);
  nfa.setFinals(finals);
  nfa.setNum(4);
  nfa.setTransitions(transitions);

  std::cout << nfa << std::endl;

  return 0;
}