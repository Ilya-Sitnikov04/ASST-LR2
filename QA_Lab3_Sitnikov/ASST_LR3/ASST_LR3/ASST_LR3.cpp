
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

/**
* @class KinoFilm
* @brief Базовый класс для представления информации о фильме.
* @image html film.jpg "Пример кинофильма"  width=300px
* Содержит данные о доходах, расходах и других параметрах фильма,
* а также методы для инициализации, чтения, отображения данных и расчета прибыли.
*/

class KinoFilm {
protected:
    double incomes; ///< Доход от показа фильма.
    double expenses; ///< Расходы на производство фильма.
    double incomeothers; ///< Доход от показа фильма в других странах.
    string names; ///< Название фильма.

public:
    /**
     * @brief Инициализирует объект класса KionFilm заданными значениями.
     *
     * @param income Доход от показа фильма.
     * @param expens Расходы на производство фильма.
     * @param incomeother Доход от показа фильма в других странах.
     * @param name Название фильма.
     */
    void Init(double income, double expens, double incomeother, string name);
    /**
     * @brief Читает данные о фильме из стандартного ввода.
     */
    void Read();
    /**
     * @brief Отображает данные о фильме в стандартный вывод.
     */
    void Display();
    /**
     * @brief Рассчитывает общую прибыль (доход минус расходы).
     *
     * @return Общая прибыль от фильма.
     */
    virtual double Total();
    /**
     * @brief Рассчитывает окупаемость фильма в процентах.
     *
     * @return Окупаемость фильма в процентах.
     */
    double Okup();
};



void KinoFilm::Init(double income, double expens, double incomeother, string name) {
    names = name;
    incomes = income;
    expenses = expens;
    incomeothers = incomeother;
}


void KinoFilm::Read() {
    string v, p, n, vo;
    cout << "Название: ";
    cin >> n;
    cout << "Доход: ";
    cin >> v;
    cout << "Доход в других странах: ";
    cin >> vo;
    cout << "Затраты: ";
    cin >> p;
    incomes = stod(v);
    expenses = stod(p);
    names = n;
    incomeothers = stod(vo);
}


void KinoFilm::Display() {
    cout << "\nНазвание: " << names << endl;
    cout << "Доход: " << incomes << endl;
    cout << "Доход в других странах: " << incomeothers << endl;
    cout << "Затраты: " << expenses << endl;
    cout << "Окупаемость в процентах: " << (incomes / expenses * 100 + incomeothers / expenses * 100) << "%\n";
}

/**
 * @brief Рассчитывает общую прибыль (доход минус расходы).
 *
 * Формула расчета общей прибыли:
 * @f[
 * \text{Total} = (\text{Incomes} + \text{IncomeOthers}) - \text{Expenses}
 * @f]
 * Где:
 * - @f$ \text{Incomes} @f$ — Доход от показа фильма в текущей стране (в рублях).
 * - @f$ \text{Expenses} @f$ — Расходы на производство фильма (в рублях).
 * - @f$ \text{IncomeOthers} @f$ — Доход от показа фильма в других странах (в рублях).
 * 
 * @return Общая прибыль от фильма.
 */

double KinoFilm::Total() {
    return incomes + incomeothers - expenses;
}

/**
 * @brief Рассчитывает окупаемость фильма в процентах.
 *
 * Формула расчета окупаемости:
 * @f[
 * \text{Okup} = \left( \frac{\text{Incomes}}{\text{Expenses}} \right) +
 * \left( \frac{\text{IncomeOthers}}{\text{Expenses}} \right)
 * @f]
 *
 * Где:
 * - @f$ \text{Incomes} @f$ — Доход от показа фильма в текущей стране (в рублях).
 * - @f$ \text{Expenses} @f$ — Расходы на производство фильма (в рублях).
 * - @f$ \text{IncomeOthers} @f$ — Доход от показа фильма в других странах (в рублях).
 *
 * @return Окупаемость фильма в процентах.
 */

double KinoFilm::Okup() {
    return (incomes / expenses) + (incomeothers / expenses);
}

/**
 * @class PremiereKinoFilm
 * @brief Производный класс для представления премьерных фильмов.
 *
 * Добавляет информацию о том, является ли фильм премьерой, и корректирует
 * расчет общей прибыли для премьерных фильмов.
 */

class PremiereKinoFilm : public KinoFilm {
private:
    int isPremiere; ///< Флаг, указывающий, является ли фильм премьерой.

public:
    /**
     * @brief Инициализирует объект класса PremiereKionFilm заданными значениями.
     *
     * @param income Доход от показа фильма.
     * @param expens Расходы на производство фильма.
     * @param incomeother Доход от показа фильма в других странах.
     * @param name Название фильма.
     * @param premiere Флаг, указывающий, является ли фильм премьерой.
     */
    void Init(double income, double expens, double incomeother, string name, int premiere);
    /**
     * @brief Читает данные о премьерном фильме из стандартного ввода.
     */
    void Read();
    /**
     * @brief Отображает данные о премьерном фильме в стандартный вывод.
     */
    void Display();
    /**
     * @brief Рассчитывает общую прибыль для премьерного фильма.
     *
     * Если фильм является премьерой, прибыль увеличивается на 10%.
     *
     * @return Общая прибыль от премьерного фильма.
     */
    double Total() override;
};


void PremiereKinoFilm::Init(double income, double expens, double incomeother, string name, int premiere) {
    KinoFilm::Init(income, expens, incomeother, name);
    isPremiere = premiere;
}


void PremiereKinoFilm::Read() {
    KinoFilm::Read();
    cout << "Является ли фильм премьерой? (1 - да, 0 - нет): ";
    cin >> isPremiere;
}


void PremiereKinoFilm::Display() {
    KinoFilm::Display();
    cout << "Премьера: " << (isPremiere ? "Да" : "Нет") << endl;
}


double PremiereKinoFilm::Total() {
    double baseSales = KinoFilm::Total();
    if (isPremiere) {
        return baseSales * 1.1;
    }
    return baseSales;
}

/**
 * @class KinoInd
 * @brief Класс для работы с двумя фильмами и подсчета общей прибыли.
 *
 * Содержит методы для инициализации, чтения, отображения данных и расчета общей прибыли.
 *
 */

class KinoInd {
private:
    private isKinoFilm P = new isKinoFilm(); ///< Обычный фильм.
    private isnotKinoFilm Np = new isnoKinoFilm(); ///< Премьерный фильм.

public:
    /**
     * @brief Инициализирует объект класса KinoInd заданными фильмами.
     *
     * @param f1 Обычный фильм.
     * @param f2 Премьерный фильм.
     */
    void Init(KinoFilm f1, PremiereKinoFilm f2);
    /**
     * @brief Читает данные о двух фильмах из стандартного ввода.
     */
    void Read();
    /**
     * @brief Отображает данные о двух фильмах в стандартный вывод.
     */
    void Display();
    /**
     * @brief Рассчитывает общую прибыль от двух фильмов.
     *
     * @return Общая прибыль от двух фильмов.
     */
    double TotalSalesForTwo();
};


void KinoInd::Init(KinoFilm f1, PremiereKinoFilm f2) {
    film1 = f1;
    film2 = f2;
}


void KinoInd::Read() {
    cout << "Обычный фильм:" << endl;
    film1.Read();
    cout << "Премьера фильма:" << endl;
    film2.Read();
}


void KinoInd::Display() {
    cout << "Обычный фильм:" << endl;
    film1.Display();
    cout << "Премьера фильма:" << endl;
    film2.Display();
}

double KinoInd::TotalSalesForTwo() {
    return film1.Total() + film2.Total();
}

/**
 * \brief Основная функция программы.
 *
 * Функция `main` является точкой входа в программу и отвечает за следующие действия:
 *
 * Создаются три объекта KinoFilm, PremiereKinoFilm, KinoInd
 *
 *Программа рассчитывает общую сумму дохода от двух фильмов с помощью метода `TotalSalesForTwo()` класса `KinoInd`, результат выводится на экран в рублях.
 *
 * @return Возвращает код завершения программы (0 — успешное завершение).
 */

int main() {
    setlocale(LC_ALL, "rus"); // Прописываем для корректного отображения русских символов

    KinoFilm film1; // Создаем объект для обычного фильма.
    PremiereKinoFilm film2; // Создаем объект для премьерного фильма.
    KinoInd cinema; // Создаем объект для управления двумя фильмами.

    // Запрашиваем у пользователя данные для двух фильмов.
    cout << "Введите данные для двух фильмов:" << endl;
    cinema.Read();

    // Выводим данные о двух фильмах.
    cout << "Данные о фильмах:" << endl;
    cinema.Display();

    // Рассчитываем и выводим общую сумму дохода от двух фильмов.
    cout << "Общая сумма дохода от двух фильмов: " << cinema.TotalSalesForTwo() << " руб." << endl;

    return 0;
}