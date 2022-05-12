# training-records

## To build:
- qmake
- make
- windeployqt [...].exe

### Its needed :
- c++17 (new mingw)
- qt >= 5.9

## JSON structure
json object -> array per year -> object per training -> object per data info

       {
          "id": 1,
          "date": "2021-04-03",
          "data": {
          }
       }


--------------

## Directory
- backend/
    - resources/   
        - files *.json  
    - src/  
        - files *.cpp  
    - files *.h  
- frontend/  
    - src/  
        - files *.cpp  
    - files *.h  
- main.cpp  
- training-records.pro  
- files *.bat
- readme.md
- .gitignore

## TO DO
