#include "TrollFile.h"
#include "Exception_Vvod.h"

TrollFile::TrollFile(const std::string& filename) : filename(filename) {}

void TrollFile::saveToFile(const std::multimap<int, Troll>& trolls) const {
    std::ofstream output(filename);
    if (!output) {
        throw Exception_Vvod("�� ������� ������� ���� ��� ������.");
    }

    for (const auto& pair : trolls) {
        pair.second.serialize(output);
        output << '\n';
    }
}

void TrollFile::loadFromFile(std::multimap<int, Troll>& trolls) const {
    std::ifstream input(filename);
    if (!input) {
        throw Exception_Vvod("�� ������� ������� ���� ��� ������.");
    }

    Troll troll;
    while (input >> troll) {
        trolls.insert({ troll.getElectricPower(), troll });
    }
}
