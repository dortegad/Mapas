#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qfiledialog.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//------------------------------------------------------------------------------------------------------
void MainWindow::on_pushButton_clicked()
{

    cv::Mat_<uchar> img = cv::imread(this->ui->lEPlantilla->text().toStdString(),cv::IMREAD_GRAYSCALE);
    cv::bitwise_not(img,img);

//    cv::imshow("imagen",img);
//    cv::waitKey();

    std::vector< std::vector< cv::Point> > regiones;
    cv::findContours(img,regiones,CV_RETR_LIST,CV_CHAIN_APPROX_NONE);
    int numRegiones = regiones.size();


    std::cout << numRegiones << " regiones encontradas" << std::endl;

    std::vector < Region> mapaRegiones;
    for (int reg=0; reg<regiones.size(); reg++)
    {
        std::cout << "region " << reg << std::endl;
        cv::Rect zona = cv::boundingRect(regiones[reg]);
        Region region;
        for (int i=zona.x; i<zona.x+zona.width; i++)
        {

            for (int j=zona.y; j<zona.y+zona.height; j++)
            {
                cv::Point punto(i,j);
                if (cv::pointPolygonTest(regiones[reg], punto, true) >= 0)
                {
                    region.puntos.push_back(punto);
                }
            }
        }
        mapaRegiones.push_back(region);
    }


    std::string fichNameImg = this->ui->lEImagen->text().toStdString();
    cv::Mat foto = cv::imread(fichNameImg);
    cv::Mat fotoFinal = cv::Mat(foto.rows,foto.cols,foto.type(),cv::Scalar(255,255,255));

    std::vector < Region >::iterator itMapaRegiones = mapaRegiones.begin();
    int reg = 0;
    for (; itMapaRegiones!=mapaRegiones.end(); itMapaRegiones++)
    {
        Region region = (*itMapaRegiones);
        std::vector < cv::Point>::iterator itPuntos = region.puntos.begin();
        std::map <double, cv::Vec3d > paleta;
        std::map <double, int > ocurrencias;
        int maxOcurrencia = 0;
        cv::Vec3b maxColor;
        for (; itPuntos!=region.puntos.end(); itPuntos++)
        {
            cv::Vec3b color = foto.at<cv::Vec3b>((*itPuntos).y,(*itPuntos).x);
            double gris = (0.2989 * color[2] + 0.5870 * color[0] + 0.1140 * color[1]);
            paleta[gris] = color;
            ocurrencias[gris]++;
            if (ocurrencias[gris] > maxOcurrencia)
            {
                maxOcurrencia = ocurrencias[gris];
                maxColor = color;
            }
        }

        std::cout << maxColor << std::endl;

        itPuntos = region.puntos.begin();
        for (; itPuntos!=region.puntos.end(); itPuntos++)
        {
            fotoFinal.at<cv::Vec3b>((*itPuntos).y,(*itPuntos).x) = maxColor;
        }
        reg++;

    }

    std::stringstream fichNameResultado;
    fichNameResultado << fichNameImg.substr(0,fichNameImg.find_last_of(".")) << "_resultado.bmp";
    cv::imwrite(fichNameResultado.str(),fotoFinal);

    std::cout << "fin" << std::endl;
}

//------------------------------------------------------------------------------------------------------
void MainWindow::on_pBPlantilla_clicked()
{
    QString imgPlantilla = QFileDialog::getOpenFileName (this,
                                               "Plantilla",
                                               tr("Image Files (*.png *.jpg *.bmp)"));

    this->ui->lEPlantilla->setText(imgPlantilla);
}

//------------------------------------------------------------------------------------------------------
void MainWindow::on_pBImagen_clicked()
{
    QString img = QFileDialog::getOpenFileName (this,
                                               "Imagen",
                                               tr("Image Files (*.png *.jpg *.bmp)"));

    this->ui->lEImagen->setText(img);
}
