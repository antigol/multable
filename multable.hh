#ifndef MULTABLE_HH
#define MULTABLE_HH

#include <QVector>
#include <QList>
#include <QString>

class MulTable
{
public:
  MulTable(int order = 0);

  void setProduct(int a, int b, int c);
  void setProductList(int a, int b, QList<int> c) {
    content[a][b] = c;
  }

  int product(int a, int b) const {
    if (content[a][b].size() == 1)
      return content[a][b].first();
    return -1;
  }
  QList<int> productList(int a, int b) const {
    return content[a][b];
  }

  int order() const { return content.size(); }

  bool isComplete() const;
  bool hasEmptyEntry() const;
  int isGroup() const;

  bool reduce();
	QList<MulTable> brute(int &limit, bool root = true);

	QList<int> eqclass(int a) const;


  bool operator !=(const MulTable& other) const;
  bool operator ==(const MulTable& other) const;

private:
  void filterProduct(int i, int j, int r);

  QVector<QVector<QList<int>>> content;
};

#endif // MULTABLE_HH
