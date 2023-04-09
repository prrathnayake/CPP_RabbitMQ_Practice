#pragma once
#include "iostream"
#include "AMQPcpp.h"
#include "consumer.h"

rabbitMQ::RabbitMQconsumer::RabbitMQconsumer()
{
}

void rabbitMQ::RabbitMQconsumer::consumeMessages(std::string url, std::string queue)
{
    AMQP amqp(url);
    rabbitMQqueue = amqp.createQueue(queue);
    rabbitMQqueue->Declare();

    while (1)
    {
        rabbitMQqueue->Get(AMQP_NOACK);

        AMQPMessage *rabbitMQmessage = rabbitMQqueue->getMessage();

        std::cout << "count: " << rabbitMQmessage->getMessageCount() << std::endl;
        if (rabbitMQmessage->getMessageCount() > -1)
        {
            uint32_t j = 0;
            std::cout << "message\n"
                      << rabbitMQmessage->getMessage(&j) << "\nmessage key: " << rabbitMQmessage->getRoutingKey() << std::endl;
            std::cout << "exchange: " << rabbitMQmessage->getExchange() << std::endl;
            std::cout << "Content-type: " << rabbitMQmessage->getHeader("Content-type") << std::endl;
            std::cout << "Content-encoding: " << rabbitMQmessage->getHeader("Content-encoding") << std::endl;
        }
        else
            break;
    }
}

rabbitMQ::RabbitMQconsumer::~RabbitMQconsumer() {}