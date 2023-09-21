/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:31:46 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/21 18:51:57 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/*  ************************************************************************* */
                    /*  Constructors and Destructor */
/*  ************************************************************************* */
RPN::RPN(): result(0), is_set(false)
{
    // std::cout << "RPN default constructor called" << std::endl;
    this->expression = NULL;
}

RPN::RPN(std::string expression): result(0), is_set(true)
{
    // std::cout << "RPN string constructor called" << std::endl;
    this->expression = const_cast<char *>(expression.c_str());
}

RPN::RPN(char expression[]): result(0), is_set(true)
{
    // std::cout << "RPN char constructor called" << std::endl;
    this->expression = expression;
}

RPN::RPN(RPN const &src)
{
    // std::cout << "RPN copy constructor called" << std::endl;
    *this = src;
}

RPN &RPN::operator=(RPN const &rhs)
{
    // std::cout << "RPN assignation operator called" << std::endl;
    if (this != &rhs)
    {
        empty_container();
        this->cont = rhs.cont;
        this->expression = rhs.expression;
        this->is_set = rhs.is_set;
        this->result = rhs.result;
    }
    return (*this);
}

RPN::~RPN()
{
    // std::cout << "RPN destructor called" << std::endl;
}


/*  ************************************************************************* */
                    /*  Member Functions */
/*  ************************************************************************* */

/**
 * @attention   temp was created to avoid strtok to modify the original expression.
 */
void    RPN::parseExpression(void)
{
    std::stack<char*>   reversed_stack;
    // char    temp[strlen(this->expression) + 1];
    char    *token;

    if (!this->is_set)
        throw ExpressionIsNotSetException();
    
    /*  ********************************************************************* */
    /*  Parse the expression content into reversed stack    */
    /*  ********************************************************************* */
    // strcpy(temp, this->expression);
    token = strtok(this->expression, " ");
    while (token != NULL)
    {
        if (is_operator(token)) {
            reversed_stack.push(token);
        } 
        else if (is_number(token)) {
            reversed_stack.push(token);
        } 
        else {
            throw InvalidExpressionExceptionNumber();
        }

        token = strtok(NULL, " ");
    }

    /*  ********************************************************************* */
                            /*  Reverse the stack    */
    /*  ********************************************************************* */
    while (!reversed_stack.empty())
    {
        this->cont.push(reversed_stack.top());
        reversed_stack.pop();
    }
}

void    RPN::evaluate(void)
{
    char    *token;
    int     l_num;
    int     r_num;

    if (this->cont.empty())
        throw EmptyContainerException();

    /*  I feel like this line should be at the end  */
    // token = this->cont.top();
    // this->cont.pop();
    // if (is_number(token))
    //     this->result = atoi(token);
    // else
    //     throw InvalidExpressionException();
    
    while (this->cont.size() != 1)
    {
        /*  **************************************************************** */
                            /*  Take the left number    */
        /*  **************************************************************** */
        token = this->cont.top();
        this->cont.pop();
        if (is_number(token) == false)
            throw InvalidExpressionExceptionNumber();
        else
            l_num = atoi(token);
        
        /*  **************************************************************** */
                            /*  Take the right number   */
        /*  **************************************************************** */
        // It is better to check the size here. But it should be ok.
        token = this->cont.top();
        this->cont.pop();
        if (is_number(token) == false)
            throw InvalidExpressionExceptionNumber();
        else
            r_num = atoi(token);
        
        if (this->cont.empty())
            throw NotEnoughOperandsException();
            
        /*  **************************************************************** */
                            /*  Take the operator    */
        /*  **************************************************************** */
        token = this->cont.top();
        this->cont.pop();
        
        if (is_operator(token) == false)
            throw InvalidExpressionExceptionOperator();
        else if (strcmp(token, "+") == 0)
            this->result = l_num + r_num;
        else if (strcmp(token, "-") == 0)
            this->result = l_num - r_num;
        else if (strcmp(token, "*") == 0)
            this->result = l_num * r_num;
        else if (strcmp(token, "/") == 0 && r_num == 0)
            throw DivisionByZeroException();
        else if (strcmp(token, "/") == 0)
            this->result = l_num / r_num;
        else
            throw std::exception();
        
        this->cont.push(const_cast<char*>(int_to_string(this->result).c_str()));
    }
}

bool    RPN::is_operator(char *token)
{
    if (strlen(token) != 1)
        return (false);
    if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')
        return (true);
    return (false);
}

bool    RPN::is_number(char *token)
{
    int i = 0;

    while (token[i])
    {
        if (!isdigit(token[i]))
            return (false);
        i++;
    }
    return (true);
}

std::string RPN::int_to_string(int n)
{
	std::stringstream ss;

	ss << n;
	return  ss.str();
}

void    RPN::empty_container(void)
{
    while (!this->cont.empty())
        this->cont.pop();
}

/*  ************************************************************************* */
                    /*  Getters and Setters */
/*  ************************************************************************* */
int         RPN::get_result(void)
{
    return (this->result);
}

std::string RPN::get_expression(void)
{
    return (std::string(this->expression));
}
