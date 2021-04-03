void Trem::run(){
    while(true){
        switch(ID){
        case 1:     //Trem A
            while((x < 310) && (y == 30)){
                x += 10;
                emit updateGUI(ID, x,y);
                msleep(200 - velocidade);
            }
            mutex.lock();
            while((x < 330) && (y == 30)){
                x += 10;
                emit updateGUI(ID, x,y);
                msleep(200 - velocidade);
            }
            while((x == 330) && (y < 150)){
                y += 10;
                emit updateGUI(ID, x,y);
                msleep(200 - velocidade);
            }
            mutex.unlock();
            while((x > 60) && (y == 150)){
                x -= 10;
                emit updateGUI(ID, x,y);
                msleep(200 - velocidade);
            }
            while((x == 60) && (y > 30)){
                y -= 10;
                emit updateGUI(ID, x,y);
                msleep(200 - velocidade);
            }
            break;
        case 2: //Trem B
            while((x < 600) && (y == 30)){
                x += 10;
                emit updateGUI(ID, x,y);
                msleep(200 - velocidade);
            }
            while((x == 600) && (y < 150)){
                y += 10;
                emit updateGUI(ID, x,y);
                msleep(200 - velocidade);
            }
            while((x > 350) && (y == 150)){
                x -= 10;
                emit updateGUI(ID, x,y);
                msleep(200 - velocidade);
            }
            mutex.lock();
            while((x > 330) && (y == 150)){
                x -= 10;
                emit updateGUI(ID, x,y);
                msleep(200 - velocidade);
            }
            while((x == 330) && (y > 30)){
                y -= 10;
                emit updateGUI(ID, x,y);
                msleep(200 - velocidade);
            }
            mutex.unlock();
            break;
        }
    }
}    
