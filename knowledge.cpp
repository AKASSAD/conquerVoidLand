#include "knowledge.h"

CKnowledge *knowledge;

CKnowledge::CKnowledge(CStatusPrinter *_printer, QObject *parent) : QObject(parent)
{
    activeTeams = 0;
//    map = new CMap(27,60, 30,300,900);
    map = new CMap(9,30, 9,27,300);
//    map = new CMap(4,5, 0,0,0);

    printer = _printer;

//    for(int i = 0; i < map->activeCells.count(); i++)
//        debug(QString("Active : %1 %2").arg(map->activeCells.at(i).first).arg(map->activeCells.at(i).second), Qt::magenta);
    //Generating robots images :
    robotsPics = new QPixmap**[4];
    for(int i = 0; i < 4; i++)
    {
        robotsPics[i] = new QPixmap*[4];
        for(int j = 0; j < 4; j++)
            robotsPics[i][j] = new QPixmap[6];
    }
    //Explorers :
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 6; j++)
            robotsPics[i][Explorer][j] = QPixmap(CExplorerRobot::draw(i,j));
    //Ninjas :
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 6; j++)
            robotsPics[i][Ninja][j] = QPixmap(CNinjaRobot::draw(i,j));
    //Terminators :
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 6; j++)
            robotsPics[i][Terminator][j] = QPixmap(CTerminatorRobot::draw(i,j));
    //Predators :
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 6; j++)
            robotsPics[i][Predator][j] = QPixmap(CPredatorRobot::draw(i,j));

}

CKnowledge::~CKnowledge()
{

}

void CKnowledge::debug(QString text, QColor color)
{
    printer->textBuffer.enqueue(CStatusText(text,color));
}
