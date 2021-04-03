#pragma once
#include "LazyIterator.h"

template<typename...Args>
std::tuple<Args...> csv_parser_iterator< Args...>::row_parse()

{
	// проверяем достигнут ли конец файла если да, ...
	if (in.eof())
	{
		// то устанавливаем current_row = -1 , как индикатор того что достигнут конец файла и теперь итератор является end'ом , и возвращаем пустой tuple
		current_row = -1;
		return std::tuple<Args...>();
	}

	std::vector<std::string> data;// здесь будем хранить строковое представление того что прочитаем из файла
	std::stringstream ss;
	uint64_t column = 1;
	try
	{
		// будем идти в цикле и будем делать проверку не достигнут ли конец файла
		while (!in.eof())
		{
			// получим символ из файла
			char c = in.get();
			// если текущий символ разделитель
			if (c == m_settings.delimiter())
			{
				// то значит что прочитанны данные из колонки, то добавим их в контейнер
				data.push_back(ss.str());
				ss.str("");
				++column;
			}
			// если текущий символ перенос строки
			else if (c == m_settings.new_line_symbol())
			{
				// значит что текущая строка прочитана полностью
				// добавим прочитанные данные из последней колонки в контейнер и увеличим номер строки
				data.push_back(ss.str());
				++current_row;
				// проверим совпадает ли количество прочитанных стролбцов с ожидаемым количеством столбцов
				if (data.size() == column_count)
					// если да, то вернем tuple с данными
					return make_tuple_(data);
				else
					// если нет, то выбросим исключение
					throw std::runtime_error("Read data count not equal column count");
			}
			// если текущий символ равен символу экранирования
			else if (c == m_settings.escaping_symbol())
			{
				// значит найдено поле которое 
				// содержит запятые, двойные кавычки, то это поле должно быть заключено в двойные кавычки. 
				// Если этого не сделать, то данные невозможно будет корректно обработать.

				// пометим, то что двойные кавычки были открыты
				bool close = false;
				// будем идти в цикле и будем делать проверку недостигнут ли конец файла
				while (!in.eof())
				{
					// получим следующий символ 
					c = in.get();
					// если получен символ экранирования
					if (c == m_settings.escaping_symbol())
						// проверим следующий символ на равество символу экранирования
						if (in.peek() != m_settings.escaping_symbol())
						{
							// если да, то пометим что двойные кавычки закрыты и выйдем из цикла
							close = true;
							break;
						}
					// если получен символ экранирования, то проигном следующий символ, так как в файле символ двойной кавычки в поле удвоен.
						else
							in.ignore(1);

					// добавим символ к текущей строке
					ss << c;
				}
				// если после выхода из цикла двойные кавычки небыли закрыты, то выбросим исключение
				if (close == false)
					throw std::runtime_error("Open symbol '\"' found, but not found closing symbol '\"'");
			}
			// если символ не является управляющим
			else
			{
				// добавим его к текущей строке
				ss << c;
			}
		}
		// сюда попадаем, если прочитана последняя строка
		// добавим прочитанные данные из последней колонки в контейнер и увеличим номер строки
		data.push_back(ss.str());
		++current_row;
		// проверим совпадает ли количество прочитанных стролбцов с ожидаемым количеством столбцов
		if (data.size() == column_count)
			// если да, то вернем tuple с данными
			return make_tuple_(data);
		else
			// если нет, то выбросим исключение
			throw std::runtime_error("read data count not equal column count");
	}
	catch (std::runtime_error const& e)
	{
		// если было выбрашено исключение из которого можно получить текст ошибки, то добавим к нему номер строки и столбца и отправим это исключение дальше
		throw std::runtime_error(std::string(e.what()) + ": row " + std::to_string(current_row) + ", column " + std::to_string(column));
	}
	catch (...)
	{
		// если было выбрашено неизвестное исключение, то сформируем сфоё исключение с номерами строки и столбца и отправим его дальше
		throw std::runtime_error("UNdefine error: row " + std::to_string(current_row) + ", column " + std::to_string(column));
	}

	return std::tuple<Args...>();
}

template<typename...Args>
auto csv_parser_iterator< Args...>::make_tuple_(std::vector<std::string> const& data)
{
	return make_tuple_impl(data, std::make_index_sequence<sizeof...(Args)>{});
}

template<typename...Args>
bool csv_parser_iterator< Args...>::operator!=(csv_parser_iterator const& r)
{
	// проверяем относятся ли итераторы к одному файлу
	if (&in != &(r.in))
		return true;
	// проверяем позицию в файле
	return current_row != r.current_row;
}

