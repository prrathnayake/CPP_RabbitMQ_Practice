#pragma once
#include "iostream"
#include "producer.h"
#include "consumer.h"

int main()
{

    std::string url = "fhmsdkaj:mV5nq8WyrPVOvJhCmgrnm0c2ZxGhl03p@vulture.rmq.cloudamqp.com:5672/fhmsdkaj";
    std::string exchange = "exchange";
    std::string queue = "queue";

    rabbitMQ::RabbitMQprocuder *rabbitMQproducer = new rabbitMQ::RabbitMQprocuder(url, exchange, queue);
    rabbitMQproducer->produceMessage("Hello");

    // rabbitMQ::RabbitMQconsumer *rabbitMQconsumer = new rabbitMQ::RabbitMQconsumer(url, queue);
    // rabbitMQconsumer->consumeMessages();
    return 0;
}