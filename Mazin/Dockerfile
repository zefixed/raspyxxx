FROM ubuntu:18.04

LABEL author="Mazin iliua 221-352"

ENV TZ=Europe/Moscow  
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone  
RUN apt-get update  
RUN apt-get install qt5-default -y  
RUN apt-get install qtbase5-dev -y
RUN apt-get install qt5-qmake  
RUN apt-get install build-essential -y 

WORKDIR /root/
RUN mkdir Exam
WORKDIR /root/Exam/

COPY *.cpp /root/Exam/
COPY *.h /root/Exam/
COPY *.pro /root/Exam/

RUN qmake -o myshop echoServer\.pro 
RUN make myshop

EXPOSE 33333