/**
 * Заголовочный файл для проверки баланса скобок
 *
 * Проверяет корректность расстановки скобок трёх видов: (), [], {}.
 */

#ifndef BRACKET_BALANCE_H
#define BRACKET_BALANCE_H

/**
 * @brief Проверка, является ли символ открывающей скобкой
 * @param character Проверяемый символ
 * @return 1 если открывающая скобка, 0 если нет
 */
int IsOpenBracket(char character);

/**
 * @brief Проверка, является ли символ закрывающей скобкой
 * @param character Проверяемый символ
 * @return 1 если закрывающая скобка, 0 если нет
 */
int IsCloseBracket(char character);

/**
 * @brief Получение соответствующей закрывающей скобки для открывающей
 * @param openBracket Открывающая скобка
 * @return Соответствующая закрывающая скобка или '\0' если не скобка
 */
char GetMatchingCloseBracket(char openBracket);

/**
 * @brief Проверка баланса скобок в строке
 * @param inputString Входная строка для проверки
 * @return 1 если скобки сбалансированы, 0 если нет
 */
int CheckBracketBalance(const char* inputString);

#endif
