#include <QtGui>
#include <QtWidgets/QLabel>
#include <QtWidgets/QGridLayout>

#include <QtCore/QDebug>

#include "inputdialog.hpp"
#include "parameters.hpp"
#include "serialport.hpp"

/******************************************************************************/

InputDialog::InputDialog( QWidget* _pWidget )
     :  QDialog(
                _pWidget
            ,       Qt::WindowTitleHint
                |   Qt::WindowSystemMenuHint
        )
{
    m_pSerialPort = nullptr;

    initializeWidget();
    connectWidget();

    setWindowTitle( "Port config" );
    setMinimumSize( 200, 120 );
}

/******************************************************************************/

InputDialog::~InputDialog()
{
    delete m_pTxtComPort;
    delete m_pTxtBaudRate;
    delete m_pCmdOk;
    delete m_pCmdCancel;
}

/******************************************************************************/

void
InputDialog::setSerialPort( VirtualPort* _pComPort ) noexcept
{
    m_pSerialPort = _pComPort;
}

/******************************************************************************/

QString
InputDialog::getComPort() const noexcept
{
    return m_pTxtComPort->text();
}

/******************************************************************************/

QString
InputDialog::getBaudRate() const noexcept
{
    return m_pTxtBaudRate->text();
}

/******************************************************************************/

void
InputDialog::initializeWidget() noexcept
{
    m_pTxtComPort = new QLineEdit;
    m_pTxtBaudRate  = new QLineEdit;

    m_pTxtComPort->setText( ProjOpt::defaultComName );
    m_pTxtBaudRate->setText( ProjOpt::defaultComBaudRate );

    QLabel* pLblComPort = new QLabel( "&COM Port:" );
    QLabel* pLblBaudRate = new QLabel( "&Baud rate:" );

    pLblComPort->setBuddy( m_pTxtComPort );
    pLblBaudRate->setBuddy( m_pTxtBaudRate );

    m_pCmdOk = new QPushButton( "&Ok" );
    m_pCmdCancel = new QPushButton( "&Cancel" );

    QGridLayout* pTopLayout = new QGridLayout;
    pTopLayout->addWidget( pLblComPort, 0, 0 );
    pTopLayout->addWidget( pLblBaudRate, 1, 0 );
    pTopLayout->addWidget( m_pTxtComPort, 0, 1 );
    pTopLayout->addWidget( m_pTxtBaudRate, 1, 1 );
    pTopLayout->addWidget( m_pCmdOk, 2,0 );
    pTopLayout->addWidget( m_pCmdCancel, 2, 1 );

    setLayout( pTopLayout );
}

/******************************************************************************/

void
InputDialog::connectWidget() noexcept
{
    connect(
            m_pCmdOk
        ,   &QPushButton::clicked
        ,   this
        ,   &InputDialog::dialogClose
    );
    connect(
            m_pCmdCancel
        ,   &QPushButton::clicked
        ,   this
        ,   &InputDialog::reject
    );
}

/******************************************************************************/

void
InputDialog::dialogClose()
{
    if( m_pSerialPort != nullptr )
        m_pSerialPort->openComPort(
                getComPort()
            ,   getBaudRate()
        );
    accept();
}

/******************************************************************************/
