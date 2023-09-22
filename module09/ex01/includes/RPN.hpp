/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:55:22 by akalimol          #+#    #+#             */
/*   Updated: 2023/09/22 14:48:49 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <cstring>
# include <cstdlib>
# include <sstream>

/**
 * @brief       Reverse Polish Notation (RPN) is a mathematical notation in which 
 *              every operator follows all of its operands.
 * 
 * @details     The class is strtok orriented.
 * 
 * @attention   Add the functionality to check all type of spaces in the expression.
 * @attention   the class is not protected against int_max overflow.
 */
class RPN
{
    private:
        /*  Member Attributes  */
        std::stack<int>   cont;
        int                 result;
        char                *expression;

        /*  Constructors and Destructor */
        RPN();

        /*  Member Functions */
        void        empty_container(void);
        bool        is_operator(char *token);
        bool        is_number(char *token);
        std::string int_to_string(int n);

    public:
        /*  Member Attributes  */
        bool    is_set;

        /*  Constructors and Destructor */
        RPN(std::string expression);
        RPN(char expression[]);
        RPN(RPN const &src);
        RPN &operator=(RPN const &rhs);
        ~RPN();

        /*  Member Functions */
        void        parseExpression(void);
        void        evaluate(char *operand);

        /*  Getters and Setters */
        int         get_result(void);
        std::string get_expression(void);

        /*  Exceptions  */
        class   EmptyContainerException: public std::exception
        {
            const char* what() const throw() {
                return ("Custom exception: Empty container");
            }
        };

        class   NotEnoughOperandsException: public std::exception
        {
            const char* what() const throw() {
                return ("Custom exception: Not enough operands");
            }
        };

        class   InvalidExpressionExceptionNumber: public std::exception
        {
            const char* what() const throw() {
                return ("Custom exception: Invalid expression. Number expected");
            }
        };

        class   InvalidExpressionExceptionOperator: public std::exception
        {
            const char* what() const throw() {
                return ("Custom exception: Invalid expression. Operator expected");
            }
        };

        class   ExpressionIsNotSetException: public std::exception
        {
            const char* what() const throw() {
                return ("Custom exception: Expression is not set");
            }
        };
        
        class   DivisionByZeroException: public std::exception
        {
            const char* what() const throw() {
                return ("Custom exception: Division by zero");
            }
        };
};


#endif