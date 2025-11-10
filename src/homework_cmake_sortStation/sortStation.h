/**
 * Заголовочный файл для алгоритма сортировочной станции Дейкстры
 */

#ifndef SORT_STATION_H
#define SORT_STATION_H

/**
 * @brief Определение приоритета оператора
 * @param operatorChar Символ оператора
 * @return Числовой приоритет (чем выше число, тем выше приоритет)
 */
int GetOperatorPriority(char operatorChar);

/**
 * @brief Проверка, является ли символ оператором
 * @param character Проверяемый символ
 * @return 1 если оператор, 0 если нет
 */
int IsOperator(char character);

/**
 * @brief Преобразование инфиксного выражения в постфиксное
 * @param infixExpression Входная строка в инфиксной записи
 * @param postfixExpression Выходной буфер для постфиксной записи
 * @return 1 если преобразование успешно, 0 если ошибка
 */
int ConvertInfixToPostfix(const char* infixExpression, char* postfixExpression);

#endif
