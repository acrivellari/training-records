#include "../widgetView.h"
#include <QHBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <cctype>
#include <QString>

WidgetView::WidgetView(Controller * c, QWidget * p)
    : QWidget{p}, controller{c}, homePage{new WV_HomePage{this, c}}, authentication{new WV_Auth{this}} {

    setWindowTitle("Training Records");
    setWindowIcon(QIcon(QString::fromStdString(controller -> getPath()) + "icon.png"));
    homePage -> hide();
    authentication -> show();
    show();
    setFixedSize(400,400);
    
    QObject::connect(authentication, &WV_Auth::sendLogin, this, &WidgetView::sendLogin);
    QObject::connect(authentication, &WV_Auth::sendRegister, this, &WidgetView::sendRegister);
    QObject::connect(authentication, &WV_Auth::showLogin, this, &WidgetView::showLogin);
    QObject::connect(authentication, &WV_Auth::showSignup, this, &WidgetView::showSignup);
}

void WidgetView::sendDataProfile() {
    homePage -> setName(controller -> getCredential("name"));
    homePage -> setSurname(controller -> getCredential("surname"));
    homePage -> setUsername(controller -> getCredential("username"));
    homePage -> setPassword(controller -> getCredential("password"));
}

void WidgetView::updateCredentials() try {
    bool isSuccessful, hasChanged;
    QString modelName, modelSurname, modelUsername, modelPassword, guiName, guiSurname, guiUsername, guiPassword;
    
    modelName = QString::fromStdString(controller -> getCredential("name"));
    modelSurname = QString::fromStdString(controller -> getCredential("surname"));
    modelUsername = QString::fromStdString(controller -> getCredential("username"));
    modelPassword = QString::fromStdString(controller -> getCredential("password"));
    guiName = homePage -> getProfileName();
    guiSurname = homePage -> getProfileSurname();
    guiUsername = homePage -> getProfileUsername();
    guiPassword = homePage -> getProfilePassword();
    
    isSuccessful = true;
    hasChanged = guiUsername != modelUsername || guiPassword != modelPassword || guiName != modelName || guiSurname != modelSurname;
 
    if (hasChanged) {
        std::string newUser, oldUser, password, name, surname;

        newUser = guiUsername.QString::toStdString();
        oldUser = modelUsername.QString::toStdString();
        password = guiPassword.QString::toStdString();
        name = guiName.QString::toStdString();
        surname = guiSurname.QString::toStdString();

        isSuccessful = controller -> changeCredentials(newUser,oldUser, password, name, surname);
    } else {
        QMessageBox::warning(this, "Change Credentials Error", "Nothing will happen, you didn't modified anything.");
    }
    if (isSuccessful == false) {
        QString messageFailure = "The change of credentials failed.\nThere were some problems with loading and/or saving the data.";
        QMessageBox::warning(this, "Change Credentials Error", messageFailure);
    }
    homePage -> closeUserForm();
} catch(BackendException* e){
    QMessageBox::warning(this, "Login Error", QString::fromStdString(e->getMessage()));    
}

void WidgetView::updateCB_listExercises() {
    for (std::string s : controller -> getTypesExercises())
        homePage -> addItem_exerciseNameCB(QString::fromStdString(s));
}

void WidgetView::sortRequest() {
    if (isSortChecked()) {
        try{
            controller -> sort(getSortType());
            closeSortForm();
            rebuildHomePage();
        } catch (BackendException* e) {
            QMessageBox::warning(homePage, "Sort Error", QString::fromStdString(e->getMessage()));
        }
    }else {
        closeSortForm();
    }
}

void WidgetView::sortById() {
    controller -> sort(true);
    rebuildHomePage();
}


bool WidgetView::isSortChecked() const {
    return homePage -> isSortChecked();
}

bool WidgetView::getSortType() const {
    return homePage -> getSortType();
}

void WidgetView::closeSortForm() {
    homePage -> closeSortForm();
}

void WidgetView::showLogin() {
    authentication -> setVisibilityLogin(true);
}

void WidgetView::showSignup() {
    authentication -> setVisibilitySignup(true);
}

void WidgetView::sendLogin() try {
    std::string username, password;
    authentication -> getCredentialsLogin(username, password);
    if (controller -> giveCredentials(username, password)) {
        controller -> load();
        showHomePage();
    }else {
        QString errorMessage = "The combination of username and password you provided doesn't exist in our database";
        QMessageBox::warning(authentication, "Login Error", errorMessage);
    }
} catch(BackendException* e){
    QMessageBox::warning(authentication, "Login Error", QString::fromStdString(e->getMessage()));
}


void WidgetView::sendRegister() try {
    std::string username, password, name, surname;
    authentication -> getCredentialsSignup(username, password, name, surname);
    if (name.empty() == false) {
        for (std::string::iterator it = name.begin(); it != name.end(); it++) {
            if (isalpha(*it) == false) {
                name.erase(it);
                it--;
            }
        }
    }
    if (surname.empty() == false) {
        for (std::string::iterator it = surname.begin(); it != surname.end(); it++) {
            if (isalpha(*it) == false) {
                surname.erase(it);
                it--;
            }
        }
    }
    if (username.size() >= 6 && password.size() >= 6 && controller -> addCredentials(username, password, name, surname)) {
        controller -> load();
        showHomePage();
    }else {
        if (username.size() >= 6 && password.size() >= 6) {
            QMessageBox::warning(authentication, "Register error", "This user already exists in our database.");
        }else if (username.size() <= 6 && password.size() <= 6) {
            QMessageBox::warning(authentication, "Register error", "Both the username and the password you chose are too short.");
        }else if (username.size() <= 6) {
            QMessageBox::warning(authentication, "Register error", "The username you chose is too short");
        }else if (password.size() <= 6) {
            QMessageBox::warning(authentication, "Register error", "The password you chose is too short");
        }
    }
} catch(BackendException* e){
    QMessageBox::warning(authentication, "Signup Error", QString::fromStdString(e->getMessage()));
}

void WidgetView::showHomePage() {
    authentication -> setVisibilityLogin(false);
    authentication -> setVisibilitySignup(false);
    authentication -> hide();

    homePage -> buildPage();
    sendDataProfile();

    QObject::connect(homePage, &WV_HomePage::updateCBListEx, this, &WidgetView::updateCB_listExercises);
    QObject::connect(homePage, &WV_HomePage::reqUpdateCredentials, this, &WidgetView::updateCredentials);
    QObject::connect(homePage, &WV_HomePage::sort_request, this, &WidgetView::sortRequest);
    QObject::connect(homePage, &WV_HomePage::sort_requestID, this, &WidgetView::sortById);
}

void WidgetView::rebuildHomePage() {
    homePage -> close();
        homePage = new WV_HomePage{this, controller};
        showHomePage(); 
}