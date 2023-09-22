/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:31:46 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/22 14:52:33 by akalimol         ###   ########.fr       */
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
    char                *token;

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
            this->evaluate(token);
        } 
        else if (is_number(token)) {
            this->cont.push(atoi(token));
        } 
        else {
            throw InvalidExpressionExceptionNumber();
        }

        token = strtok(NULL, " ");
    }
    if (this->cont.size() != 1)
        throw InvalidExpressionExceptionOperator();
}

void    RPN::evaluate(char    *token)
{
    int     l_num;
    int     r_num;

    /*  **************************************************************** */
                        /*  Take the arguments    */
    /*  **************************************************************** */
    /*  Take the left number    */
    if (this->cont.empty()) {
        throw NotEnoughOperandsException();
    }
    else {
        r_num = this->cont.top();
        this->cont.pop();
    }
    
    /*  Take the right number   */
    if (this->cont.empty()) {
        throw NotEnoughOperandsException();
    }
    else {
        l_num = this->cont.top();
        this->cont.pop();
    }
    
    /*  **************************************************************** */
                        /*  Evaluate the expression    */
    /*  **************************************************************** */
    if (strcmp(token, "+") == 0)
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
    
    /*  Push back to the stack  */
    this->cont.push(this->result);
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
