
# Задача *

Абстрактная задача на закрепление понимания темы классов, наследования, шаблонов, стандартной библиотеки и т.д.
Конкретных требований нет, кроме использования вышеперечисленных тем.

Задача звучит так: 
* Создать менеджера файлов, который может записывать в заданные файлы или в список файлов или во все файлы, за которыми следит менеджер через метод write
* Менеджер может читать из определённых файлов и выводит прочитанное на консоль (например "read <value> from <filename>).
* Использовать файлы fileWritter.cpp и fileReader.cpp как пример записи в файл и чтения из файла. Менять их можно, копировать и всё что угодно делать разрешается.
* С применением наследования и классов, возможно перегрузки операторов (например readWriteManager += fileWriter("test.txt") - перегрузить оператор += чтобы добавлять к файловому менеджеру записывающий класс) реализовать интерфейсы IReader, IWriter (по возможности сделать их абстрактными) с методами read, write соответственно (желательно шаблонными, или можно просто std::string в качестве аргумента). Далее создать потомков наследников интерфейсов в виде fileReader, fileWriter и, например, consoleWriter (которые выводят в std::cout). Можно сделать ещё больше классов, например в виде jsonReader, jsonWriter и при записи и чтении сделать метод с использованием формирования json (самое простое это передавать шаблонным аргументом std::map и эти пары ключ:значение записывать через запятую в скобках {}, как и в обычном json), или ещё xmlReader и xmlWriter (с тегами <key>value<key/>).
* Менеджер файлов (например readWriteManager) может иметь множество методов(для него так же можно создать интерфейс, но не обязательно, ведь менеджер будет один), например writeAll(std::string line), writeAll(std::vector<std::string> lines), writeToFile(std::string to_file, std::string line), writeToFile(std::vector<std::string> to_files, std::string line) и методы readFromFile(std::string from_file, T& value), std::string readFromConsole(), возможно addWriter(IWriter* writer) (указатель нужен, чтобы избещать конструктора копирования или создания временных объектов, ведь в конструкторе мы открываем файл, а в дектрукторе закрываем) и другие методы которые вам кажутся нужными.


Даты сдачи - действительная в течении месяца

Для сдачи можно выложить на гит в отдельную ветку и скинуть ссылку или показать очно. (pull request делать необязательно)

* Все вопросы можно задавать в любой форме. Открыто в беседу или в личные сообщения.
