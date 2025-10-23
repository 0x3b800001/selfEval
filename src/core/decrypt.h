#define LEMON_KEY QString("123456")

#include <QString>
#include <QFile>
#include <random>

class Decrypt {
  private:
    QString pth;
  public:
    Decrypt(QString Path) {
      Path = QFileInfo(Path).absoluteFilePath();
      std::random_device rd;
      std::mt19937 rng(rd());
      pth = "/tmp/";
      for (int i = 0; i <= 20; ++i) {
        pth += "1234567890qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM"[std::uniform_int_distribution<>(0, 61)(rng)];
      }
      if (std::system(("unzip -q -P " + LEMON_KEY + " -d " + pth + " \"" + Path + "\" > /dev/null 2>&1").toStdString().c_str()) || 
          !QFileInfo(pth + "/secret").isFile()) {
        std::system(("rm -r " + pth + " > /dev/null 2>&1").toStdString().c_str()) && 1;
        pth = "Error";
      }
    }
    QString secret() { return pth + "/secret"; }
    ~Decrypt() {
      if (pth[0] == '/') {
        std::system(("rm -r " + pth + " > /dev/null 2>&1").toStdString().c_str()) && 1;
      }
    }
};