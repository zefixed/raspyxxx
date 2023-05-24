FROM postgres

ENV ip_db = "172.0.0.2"
ENV TZ=Europe/Moscow
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN apt-get update
RUN apt-get install qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools -y
RUN apt-get install build-essential -y
RUN apt install libqt5sql5-psql

WORKDIR /root/
RUN mkdir server
WORKDIR /root/server/
COPY *.cpp /root/server/
COPY *.h /root/server/
COPY *.pro /root/server/

RUN qmake echoServer.pro
RUN make

EXPOSE 33333
EXPOSE 5432

ENTRYPOINT ["./echoServer \"ip_db\" "]

