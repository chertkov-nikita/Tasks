from xml.etree import ElementTree as ET


# Вам дано описание пирамиды из кубиков в формате XML.
# Кубики могут быть трех цветов: красный (red), зеленый (green) и синий (blue).
# Для каждого кубика известны его цвет, и известны кубики,
# расположенные прямо под ним.
# Введем понятие ценности для кубиков. Самый верхний кубик, соответствующий корню XML
# документа имеет ценность 1. Кубики, расположенные прямо под ним, имеют ценность 2.
# Кубики, расположенные прямо под нижележащими кубиками, имеют ценность 3. И т. д.
# Ценность цвета равна сумме ценностей всех кубиков этого цвета.
# Выведите через пробел три числа: ценности красного, зеленого и синего цветов.

class XMLParser:
    depth = 0
    red_cube = 0
    green_cube = 0
    blue_cube = 0

    def start(self, tag, attrib):
        self.depth += 1
        if tag == 'cube':
            self.red_cube += self.depth if attrib['color'] == 'red' else 0
            self.green_cube += self.depth if attrib['color'] == 'green' else 0
            self.blue_cube += self.depth if attrib['color'] == 'blue' else 0

    def end(self, tag):
        self.depth -= 1

    def data(self, data):
        pass

    def close(self):
        return self.red_cube, self.green_cube, self.blue_cube


def main():
    target = XMLParser()
    parser = ET.XMLParser(target=target)
    parser.feed(input())
    parser.close()
    print(target.red_cube, target.green_cube, target.blue_cube)


if __name__ == '__main__':
    main()
