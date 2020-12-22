package com.example.demo.entity;

import javax.validation.ConstraintValidator;
import javax.validation.ConstraintValidatorContext;

/**
 * @FileName: MyCustomConstraintValidator
 * @author: qianBaoLi
 * @date: 2020/11/13 19:14
 * @Description: null
 */
public class MyCustomConstraintValidator
        implements ConstraintValidator<MyCustomConstraint,String> {
    @Override
    public void initialize(MyCustomConstraint constraintAnnotation) {

    }

    @Override
    public boolean isValid(String s, ConstraintValidatorContext constraintValidatorContext) {
        if("上海".equals(s) || "北京".equals(s)) {
            return true;
        }
        return false;
    }
}
