package com.example.demo.entity;

import lombok.Data;
import org.hibernate.validator.constraints.Length;
import org.hibernate.validator.constraints.NotBlank;

import javax.validation.constraints.Email;
import javax.validation.constraints.Max;
import javax.validation.constraints.Min;
import javax.validation.constraints.NotNull;
import java.io.Serializable;

/**
 * @FileName: User
 * @author: qianBaoLi
 * @date: 2020/11/12 14:42
 * @Description: null
 */
@Data
public class User implements Serializable {
    private Long id;

    @NotBlank(message = "the user name can not be null")
    @Length(min = 5, max = 20, message = "the length of name can only between 5 and 20 characters")
    private String name;

    @NotNull(message = "the age can not be null")
    @Min(value = 18, message = "minimum age is 18 years old")
    @Max(value = 60, message = "Maximum age is 60")
    private Integer age;

    @Email(message = "please input you email")
    @NotNull(message = "email can not be null")
    private String email;

    @MyCustomConstraint
    private String answer;
}
