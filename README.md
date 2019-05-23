# DesignPatternsCalculator2

This calculator takes in expressions one-by-one and calculates the answer until the user types "QUIT". It supports add, subtract, multiply, divide, modulus, number and parenthesis expressions. The calculator takes the expressions in as infix expressions and converts them into a postfix tree structure using the composite pattern. The program iterates through the infix expression and uses a conversion algorithm that acts as the commander for a builder pattern that builds the composite, postfix tree node-by-node. Each node represents a mathematical expression including numbers or operations such as multiply or divide. A visitor pattern is used to traverse the expression using post-order traversal and executes the expression. All of the methods/patterns are accessed through a wrapper/façade pattern called “Calculator”.
