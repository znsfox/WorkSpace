package fox.validator;


import fox.pojo.Transaction;
import org.springframework.validation.Errors;
import org.springframework.validation.Validator;

/**
 * @description:
 * @author: fox
 * @date: 2020/10/31 14:17
 */
public class TransactionValidator implements Validator {

    @Override
    public boolean supports(Class<?> clazz) {
        //judge if it is Transaction,if it is true ,then validate it
        return Transaction.class.equals(clazz);
    }

    @Override
    public void validate(Object target, Errors errors) {
    Transaction transaction = (Transaction)target;
    double dis = transaction.getAmount() - (transaction.getPrice()*transaction.getQuantity());
    if(Math.abs(dis) > 0.01) {
        errors.rejectValue("amount",null,"the amount don't match the price and quantity");
    }
    }
}
