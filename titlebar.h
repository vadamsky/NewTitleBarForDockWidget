#ifndef Titlebar_H
#define Titlebar_H
#include <QWidget>
#include <QDialog>
#include <QIcon>
#include <QLabel>
#include <QMouseEvent>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QMessageBox>

enum log_sort_directions_t {
  log_sort_strait,//прямое
  log_sort_back//обратное
};

class Titlebar : public QDialog { //QWidget
  Q_OBJECT
private:
  QWidget* parent;
  QPoint cursor;
  QPushButton* push_button;
  QString btn_text;
  QLabel* label_title;
  log_sort_directions_t sort_dir;
public:
  Titlebar( QWidget* parent ) : parent( parent ) {
    btn_text = "My push button";
    sort_dir = log_sort_strait;
    label_title = new QLabel( parent->windowTitle() );
    push_button = new QPushButton(btn_text);
    //pb_sort->setIcon(QIcon(":images/synchronize16.png"));

    int pb_sz = 18;
    //pb_sort->setFixedSize(pb_sz + 200, pb_sz + 10); //100);
    QObject::connect(push_button, SIGNAL(clicked()),
                     this, SLOT(on_push_button()));

    QPushButton* pb_close = new QPushButton( "x" );
    pb_close->setFixedSize(pb_sz, pb_sz);

    //setStyleSheet("background: rgb(200, 200, 200);width: 2px;height: 2px;background-color: red; border-radius: 10px}");

    this->setWindowFlags(Qt::Window
                         | Qt::WindowMinimizeButtonHint
                         | Qt::WindowMaximizeButtonHint
                         | Qt::CustomizeWindowHint);

    QHBoxLayout* layout = new QHBoxLayout( this );

    QHBoxLayout* layoutInner = new QHBoxLayout();
    layoutInner->addWidget(label_title, 1 );
    layoutInner->addWidget(push_button, 1);

    layout->addLayout(layoutInner, 1);

    layout->addSpacing(200);
    layout->addWidget(pb_close );

    connect( pb_close, SIGNAL( clicked() ), parent, SLOT( close() ) );
  }

protected:
  void mousePressEvent( QMouseEvent* event ) {
    if( event->button() == Qt::LeftButton )
      cursor = event->globalPos() - geometry().topLeft();
    event->ignore();
  }

  void mouseMoveEvent( QMouseEvent* event ) {
    if( event->buttons() & Qt::LeftButton )
      parent->move( event->globalPos() - cursor );
    event->ignore();
  }
signals:
  void logValue_sortDirection(log_sort_directions_t);

public slots:
  void on_push_button() {
      QMessageBox::information(this,"","action on push button");
//    QFontMetrics metrics(pb_sort->font());
//    int w = metrics.width(text);
//    int h = metrics.height();
//    pb_sort->setFixedSize(w + 10, h + 10);
  }
};

#endif // Titlebar_H
