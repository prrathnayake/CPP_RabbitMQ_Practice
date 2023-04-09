#pragma once
#include "iostream"
#include "AMQPcpp.h"
#include "producer.h"

rabbitMQ::RabbitMQprocuder::RabbitMQprocuder(std::string url, std::string exchange, std::string queue)
{
    AMQP amqp(url);

    rabbitMQexchange = amqp.createExchange(exchange);
    rabbitMQexchange->Declare(exchange, "fanout");

    rabbitMQqueue = amqp.createQueue(queue);
    rabbitMQqueue->Declare();
    rabbitMQqueue->Bind(exchange, "");

    rabbitMQexchange->setHeader("Delivery-mode", 2);
    rabbitMQexchange->setHeader("Content-type", "text/text");
    rabbitMQexchange->setHeader("Content-encoding", "UTF-8");
}

void rabbitMQ::RabbitMQprocuder::produceMessage(std::string message)
{
    rabbitMQexchange->Publish(message, "");
}

rabbitMQ::RabbitMQprocuder::~RabbitMQprocuder() {}
