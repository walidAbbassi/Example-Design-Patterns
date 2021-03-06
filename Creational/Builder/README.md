## Builder

Builder pattern has creational purpose and separates the construction of a complex object 
from its representation so that the same construction process can create different 
representations. It is object pattern, ie. relationships can be changed at run-time
and are more dynamic. Often is used for building composite structures but constructing
objects requires more domain knowledge of the client than using a Factory.
It is used to construct a complex object step by step and the final step will return the object


### UML class diagram example for the Builder Design Pattern.

 - Product – The product class defines the type of the complex object that is to be generated by the builder pattern.
 - Builder – This abstract base class defines all of the steps that must be taken in order to correctly create a product. 
		Each step is generally abstract as the actual functionality of the builder is carried out in the concrete subclasses. 
		The GetProduct method is used to return the final product. The builder class is often replaced with a simple interface.
 - ConcreteBuilder – There may be any number of concrete builder classes inheriting from Builder. 
		These classes contain the functionality to create a particular complex product.
 - Director – The director class controls the algorithm that generates the final product object. 
		A director object is instantiated and its Construct method is called. 
		The method includes a parameter to capture the specific concrete builder object that is to be used to generate the product. 
		The director then calls methods of the concrete builder in the correct order to generate the product object. 
		On completion of the process, the GetProduct method of the builder object can be used to return the product.
 
<p align="center">
<img 
src="https://github.com/walidAbbassi/Example-Design-Patterns/blob/master/Creational/Builder/Builder.PNG">
</p>

### When to use

* the algorithm for creating a object should be independent of the parts and how they're assembled
* the construction process must allow different representations for the object that's constructed  
