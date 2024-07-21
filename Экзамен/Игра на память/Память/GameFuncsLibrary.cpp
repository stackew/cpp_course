#include <iostream>

#include "GameFuncsLibrary.h"

bool IsMatch(Card& card1, Card& card2, GameField const& field)
{
    return field[card1.RowIndex][card1.ColIndex] == field[card2.RowIndex][card2.ColIndex]; //�������� ������� �� �����
}

bool IsAlreadyOpened(Card& card, std::vector<Card> const& opened_cards)
{
    for (const Card& opened_card : opened_cards)
    {
        if (card.RowIndex == opened_card.RowIndex &&
            card.ColIndex == opened_card.ColIndex)                 //�������� ���� �� ����� ������� �����
        {
            return true;
        }
    }
    return false;
}

bool IsFree(GameField const& field, const int& row_pos,
    const int& col_pos)
{
    return field[row_pos][col_pos] == NULL;            //�������� �������� �� ������� � ����
}

void PrintMarking(const int& amount)
{
    int count = 0;
    std::cout << "  ";
    for (size_t i = 0; i != amount; i++)
    {
        std::cout << count++ << " ";
    }
    //������� ���������� ����
    std::cout << std::endl << " ";

    for (size_t i = 0; i != count; i++)
    {
        std::cout << "==";
    }

    std::cout << std::endl;
}

void PrintClosedField(ClosedGameField const& closed_field)
{
    size_t count = 0;
    PrintMarking(closed_field.size());
    for (size_t i = 0; i != closed_field.size(); i++)
    {
        std::cout << count++ << "|";
        for (size_t j = 0; j != closed_field[i].size(); j++)    //������� ����� � ��������� �������
        {
            std::cout << closed_field[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void PrintOpenedCards(const Card& card1, const Card& card2, GameField const& field,
    std::vector<Card> const& opened_cards)
{
    Card card;
    size_t count = 0;

    PrintMarking(field.size());
    for (size_t i = 0; i != field.size(); i++)
    {
        std::cout << count++ << "|";
        for (size_t j = 0; j != field[i].size(); j++)
        {
            card.RowIndex = i;
            card.ColIndex = j;
            if (i == card1.RowIndex && j == card1.ColIndex)
            {
                std::cout << ConvertToSymbols[field[i][j]] << " ";                        //������� ����, � ��������� �������
            }
            else if (i == card2.RowIndex && j == card2.ColIndex)
            {
                std::cout << ConvertToSymbols[field[i][j]] << " ";;
            }
            else if (IsAlreadyOpened(card, opened_cards))
            {
                std::cout << "  ";
            }
            else
            {
                std::cout << "#" << " ";
            }
        }
        std::cout << std::endl;
    }
}

GameSettings GetGameSettings(FieldSize const& field_size)
{
    return FieldSettings.at(field_size);
}

void AddPair(GameField& field, const int& el, const int& size)
{
    bool isCheck = false;
    int rand_row = rand() % size;
    int rand_col = rand() % size;

    while (!isCheck)
    {
        if (IsFree(field, rand_row, rand_col))
        {
            field[rand_row][rand_col] = el;                        //���������� ���� �����
            isCheck = true;
        }
        else
        {
            rand_row = rand() % size;
            rand_col = rand() % size;
        }
    }
}

void GenerateField(GameField& field, const GameSettings& settings)
{
    std::vector<int> used_nums;

    for (size_t i = 0; i != settings.rows; i++)
    {
        for (size_t j = 0; j != settings.cols; j++)
        {
            if (IsFree(field, i, j))
            {
                int el;
                while (true)
                {
                    el = rand() % settings.max_rand_num;
                    if (std::find(used_nums.begin(), used_nums.end(), el) == used_nums.end()) //��������� �����
                    {
                        field[i][j] = el;
                        used_nums.push_back(el);
                        break;
                    }
                }
                AddPair(field, el, settings.rows);
            }
        }
    }
}

bool IsCorrect(Card& card1, Card& card2, GameField const& field,
    std::vector<Card> const& OpenedCards)
{
    std::cout << "������� ������ 1 �����, ������� ������ ������� (������, �������): ";
    std::cin >> card1.RowIndex >> card1.ColIndex;
    std::cout << "������� ������ 2 �����, ������� ������ ������� (������, �������): ";
    std::cin >> card2.RowIndex >> card2.ColIndex;
    if (IsAlreadyOpened(card1, OpenedCards) || IsAlreadyOpened(card2, OpenedCards)
        || (card1.RowIndex == card2.RowIndex && card1.ColIndex == card2.ColIndex))
    {
        std::cout << "���� �� ���� ��� ���� �������!" << std::endl;
        return false;
    }
    else if (card1.RowIndex >= field.size() || card1.RowIndex < 0                               //�������� ���� �� ������������
        || card1.ColIndex >= field.size() || card1.ColIndex < 0 ||
        card2.RowIndex >= field.size() || card2.RowIndex < 0 ||
        card2.ColIndex >= field.size() || card2.ColIndex < 0)
    {
        std::cout << "����� � ����� �������� �� ����������" << std::endl;
        return false;
    }
    else
    {
        return true;
    }
}

void InitClosedField(ClosedGameField& closed_field)
{
    for (size_t i = 0; i != closed_field.size(); i++)
    {
        for (size_t j = 0; j != closed_field[i].size(); j++)        //���������� ���������� ���� � ���������� ����������
        {
            closed_field[i][j] = '#';
        }
    }
}

FieldSize ModeSelection()
{
    size_t size_val;
    std::cout << "\n---���� �� ������---" << std::endl
        << "1)2x2" << std::endl
        << "2)4x4" << std::endl
        << "3)6x6" << std::endl
        << "����� ������� ����: ";
    std::cin >> size_val;
    while (size_val > 3 || size_val < 1)
    {
        std::cout << "�� ����� ���-�� �� ���!" << std::endl;
        std::cout << "������� ������ ��������: ";
        std::cin >> size_val;
    }

    return static_cast<FieldSize>(size_val);
}

GameStatistics Turns(ClosedGameField& closed_field, GameField& field)
{
    GameStatistics statistics;
    std::vector<Card> opened_cards;
    int turn_val = 0;
    Turn which_turn;

    do
    {
        std::cout << "---������ ������---" << std::endl;

        PrintClosedField(closed_field);

        std::cout << "����� " << turn_val + 1 << " �����:" << std::endl;
        Card card1, card2;
        while (!IsCorrect(card1, card2, field, opened_cards));

        statistics.flips_count += 2;

        PrintOpenedCards(card1, card2, field, opened_cards);

        which_turn = static_cast<Turn>(turn_val);
        if (IsMatch(card1, card2, field))
        {
            closed_field[card1.RowIndex][card1.ColIndex] = ' ';
            closed_field[card2.RowIndex][card2.ColIndex] = ' ';

            opened_cards.push_back(card1);
            opened_cards.push_back(card2);

            switch (which_turn)
            {
            case PLAYER1:
                statistics.p1_points++;                                               //�������� �� ���������� ����
                std::cout << "������ ����� �������� ����!" << std::endl;
                break;
            case PLAYER2:
                statistics.p2_points++;
                std::cout << "������ ����� �������� ����!" << std::endl;
                break;
            default:
                break;
            }
            PlaySound(TEXT("correct-answer-sound.wav"), NULL, SND_FILENAME | SND_SYNC);
        }
        else
        {
            PlaySound(TEXT("wrong-answer-sound.wav"), NULL, SND_FILENAME | SND_SYNC);
        }

        switch (which_turn)
        {
        case PLAYER1:
            turn_val = PLAYER2;
            break;
        case PLAYER2:                   //������� ���� ������� ������
            turn_val = PLAYER1;
            break;
        default:
            break;
        }

        std::cout << "���������� ����� ������� ������: " << statistics.p1_points << std::endl;
        std::cout << "���������� ����� ������� ������: " << statistics.p2_points << std::endl;

        std::cout << "---����� ������---" << std::endl;
        _getch();

        system("cls");
    } while (statistics.p1_points + statistics.p2_points !=
        (field.size() * field.size()) / 2);
    return statistics;
}

void OutputStatistics(const GameStatistics& statistics)
{
    if (statistics.p1_points > statistics.p2_points)
    {
        std::cout << "---������� 1 ����� �� ������: " << statistics.p1_points << " �����---"
            << std::endl;
    }
    else if (statistics.p1_points < statistics.p2_points)
    {
        std::cout << "---������� 2 ����� �� ������: " << statistics.p2_points << " �����---"       //���������� ����������
            << std::endl;
    }
    else
    {
        std::cout << "-----���� ����������� ������!-----" << std::endl;
    }
    std::cout << "����� ����: " << statistics.game_duration.count() << std::endl;
    std::cout << "���������� ����������� ����: " << statistics.flips_count << std::endl;
}

void PlayGame(FieldSize field_size)
{

    system("cls");

    GameSettings settings = GetGameSettings(field_size);

    GameField field(settings.rows, std::vector<int>(settings.cols));                          //��������� �������� ����
    GenerateField(field, settings);

    ClosedGameField closed_field(settings.rows, std::vector<char>(settings.cols));
    InitClosedField(closed_field);

    auto timer_start = std::chrono::high_resolution_clock::now();

    GameStatistics statistics = Turns(closed_field, field);;

    auto timer_end = std::chrono::high_resolution_clock::now();
    statistics.game_duration = timer_end - timer_start;


    OutputStatistics(statistics);
}
