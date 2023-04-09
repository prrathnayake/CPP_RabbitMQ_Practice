#pragma once
#include <iostream>

#include <utils/ThreadPool.h>
#include <rabbitMQ/producer.h>
#include <rabbitMQ/consumer.h>

void sendMessage(rabbitMQ::RabbitMQprocuder *rabbitMQproducer)
{
    rabbitMQproducer->produceMessage("Hello");
}

void consumeMessage(rabbitMQ::RabbitMQconsumer *rabbitMQconsumer)
{
    rabbitMQconsumer->consumeMessages();
}

int main()
{
    utils::ThreadPool pool;
    // pool.addThread("consumer");
    pool.addThread("producer");

    std::string url = "fhmsdkaj:mV5nq8WyrPVOvJhCmgrnm0c2ZxGhl03p@vulture.rmq.cloudamqp.com:5672/fhmsdkaj";
    std::string exchange = "exchange";
    std::string queue = "queue";

    // rabbitMQ::RabbitMQconsumer *rabbitMQconsumer = new rabbitMQ::RabbitMQconsumer(url, queue);
    // pool.addTask("consumer", std::bind(consumeMessage, rabbitMQconsumer));

    rabbitMQ::RabbitMQprocuder *rabbitMQproducer = new rabbitMQ::RabbitMQprocuder(url, exchange, queue);
    pool.addTask("producer", std::bind(sendMessage, rabbitMQproducer));

    pool.joinAll();
    return 0;
}