package com.example.demo;

import lombok.Data;
import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.stereotype.Component;

import java.util.List;

/**
 * @FileName: CoExamplee
 * @author: qianBaoLi
 * @date: 2020/11/9 15:23
 * @Description: load configuration file
 */
@Data
@Component
@ConfigurationProperties(prefix = "com.example")
public class CoExample {
    private String name;
    private int age;
    private List<String> address;
}
