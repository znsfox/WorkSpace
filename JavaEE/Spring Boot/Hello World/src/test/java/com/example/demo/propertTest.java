package com.example.demo;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;

/**
 * @description:
 * @FileName: propertTest
 * @author: qianBaoLi
 * @date: 2020/11/9 14:51
 * @Description: a test
 */
@SpringBootTest
@RunWith(SpringRunner.class)
public class propertTest {
    @Value("${age}")
    private int age;

    @Value("${name}")
    private String name;

    @Test
    public void getAge() {
        System.out.println(age);
    }

    @Test
    public void getName() {
        System.out.println(name);
    }

    @Autowired
    private GetPersonInfoProperties getPersonInfoProperties;
    @Test
    public void getpersonproperties() {
        System.out.println(getPersonInfoProperties.getAge()
                +getPersonInfoProperties.getName());
    }
}
