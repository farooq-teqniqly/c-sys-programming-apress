FROM teqniqly/cbuild:latest AS build

WORKDIR /src
COPY CMakeLists.txt ./
COPY main.c ./
RUN cmake . && make

FROM ubuntu:latest as deploy
WORKDIR /app
COPY --from=build /src/mt ./
CMD ["./mt"]
