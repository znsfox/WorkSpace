package com.example.demo.entity;

import javax.validation.Constraint;
import javax.validation.Payload;
import java.lang.annotation.ElementType;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;

/**
 * @FileName: MyCustomConstraint
 * @author: qianBaoLi
 * @date: 2020/11/12 16:10
 * @Description: null
 */
@Target({ElementType.FIELD})
@Retention(RetentionPolicy.RUNTIME)
@Constraint(validatedBy = MyCustomConstraintValidator.class)
public @interface MyCustomConstraint {
    String message() default "请输入中国经济或者政治中心的名字：\n";
    Class<?>[] groups() default {};
    Class<? extends Payload>[] payload() default {};
}
